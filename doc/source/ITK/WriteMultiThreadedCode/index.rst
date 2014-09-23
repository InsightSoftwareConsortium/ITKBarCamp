.. index:: multi-threading

.. _Writing Multi-Threaded Code:

Write Multi-Threaded Code
=========================

Description
-----------
  In this session, we discuss how to write multi-threaded
  ITK code that uses native operating system CPU threads.

Introduction
------------

Writing parallel algorithms to take advantage of multi-processor or multi-core
systems can significantly improve the algorithms speed (although there are
exceptions!).  In image analysis, we often encounter `embarrassingly parallel`_
problems.  For example, every output pixel of an algorithm can often be computed
independently from the other output pixels.

In an `itk::ImageToImageFilter`_
--------------------------------

.. figure:: Threading.gif
  :align: center

  CPU-based threading in a shared-memory SMP architecture.

The output image is a single contiguous block on memory that is used for all
processing threads. Each thread is informed which pixels they are responsible
for producing the output values. All the threads write to this same block of
memory but a given thread is only allowed to set specific pixels.

A multi-threaded filter provides an implementation of the
`ThreadedGenerateData()`_ method as opposed to the normal single threaded
`GenerateData()`_ method. A superclass of the filter will spawn several threads
(usually matching the number of processors in the system) and call
`ThreadedGenerateData()`_ in each thread specifying the portion of the output
that a given thread is responsible for generating. For instance, on a dual
processor computer, an image processing filter will spawn two threads, each
processing thread will generate one half of the output image, and each thread is
restricted to writing to separate portions of the output image. Note that the
"entire" input and "entire" output images (i.e. what would be available normally
to the `GenerateData()`_ method whether or not streaming is being peformed) are
available to each call of `ThreadedGenerateData()`_.  Each thread is allowed to
read from anywhere in the input image but each thread can only write to its
designated portion of the output image.

When writing a threaded filter, the `ThreadedGenerateData()`_ method must be
`thread-safe`_.  Thread safety requires that multiple threads do not write to the
same location in memory at the same time.  To avoid this problem, `thread-local
storage`_ is often used.  Intermediate results are written to thread-local data
structures then merged in a single-threaded way after parallel processing.
To facilitate this common strategy, the `default ImageSource implementation of
GenerateData()`_ also runs a `BeforeThreadedGenerateData()`_ and
`AfterThreadedGenerateData()`_ method, which are null by default.  To use
`thread-local storage`_, create the thread-specific data structures in
`BeforeThreadedGenerateData()`_ and merge the results in
`AfterThreadedGenerateData()`_.  For an example see the `implementation of the
itk::MinimumMaximumImageFilter`_.

`BeforeThreadedGenerateData()`_ is also commonly used to perform single-threaded
processing to prepare for the `ThreadedGenerateData()`_ call.

With `itk::DomainThreader`_
---------------------------

While the `ThreadedGenerateData()`_ method in an `itk::ImageToImageFilter`_
make most `data-parallel`_ operations easy to code, it does not fit our needs.
We may want to:

* Perform more than one multi-threaded operation in a filter.
* Split our data into something other than `itk::ImageRegion`'s.
* Do multi-threading outside an `itk::ImageSource`.

The `itk::DomainThreader`_ class overcomes these limitations.

It is possible to have more than one `itk::DomainThreader`_ member in a class,
so it is possible to perform multiple different multi-threaded operations in a
single filter `Update()`.  The multi-threaded operations can be performed
multiple times within a loop, be conditionally performed, etc.

The `itk::DomainThreader`_ class is templated over the data domain to be
split/partitioned, so it can operate on `itk::ImageRegion's like
ThreadedGenerateData()`_ but also `index ranges in an itk::Array`_ or `a range
specified by Standard Library iterators`_ depending on which class is selected
to partition the domain.

The `itk::DomainThreader`_ class structure is similar to the `itk::ImageSource`_
structure.  The analog of `itk::ImageSource`_'s::

  BeforeThreadedGenerateData()
  ThreadedGenerateData( const OutputImageRegionType & outputRegionForThread, ThreadIdType threadId )
  AfterThreadedGenerateData()

in `itk::DomainThreader`_ are the::

  BeforeThreadedExecution()
  ThreadedExecution( const DomainType & subDomain, const ThreadIdType threadId )
  AfterThreadedExecution()

methods.

To use `itk::DomainThreader`_, create a Threader subclass of
`itk::DomainThreader`_.  This subclass will be templated over *TAssociate*, the
type of the class that will use the new subclass to perform the multi-threaded
operation.  The *Associate* class should declare and instantiate a member
*Threader*.  The type of the Threader will be templated with the Associate's
*Self* type.  The Associate will also declare the *Threader* a `friend class`_,
so that it can access its private and protected members with
*this->m_Associate->m_AssociateMemberName*.  When the Associate wants to perform
the multi-threaded operation, it will call `Execute( this, completeDomain )` on
the member Threader.

A `cell counting example`_ can be found in the ITKExamples project.

With `itk::MultiThreader`_
---------------------------

The `itk::MultiThreader`_ can be used to manually spawn and terminate your own
methods to operate on threads in a platform-independent way.  However, there is
much more code overhead and opportunity for errors compared to
`itk::ImageToImageFilter`_ or `itk::DomainThreader`_.  For an example that
applies `itk::MultiThreader`_ directly, see `the implementation of the
CannyEdgeDetectionImageFilter`_.

Static methods on `itk::MultiThreader`_ can also be used to control default
number of threads or a global maximum number of threads. When writing filters
designed to work with other processors or future processors, however, care
should be taken to avoid hard-coding the number of threads utilized.

Setting the default global number of threads to one can be useful when writing
or debugging multi-threaded code.  The static method on `itk::MultiThreader`_
can be used or the environmental variable *ITK_GLOBAL_DEFAULT_NUMBER_OF_THREADS*
can be set to *1* to achieve the desired effect.

Locking classes
---------------

Note that ITK has a few classes to perform thread synchronization, such as the
`itk::SimpleFastMutexLock`_, but these should be avoided if possible because of
performance reasons.

Video
-----

.. youtube:: aih7O1zQook

See also
--------

* `ITK Doxygen Threading Documentation`_

.. _embarrassingly parallel: http://en.wikipedia.org/wiki/Embarrassingly_parallel
.. _ITK Doxygen Threading Documentation: http://www.itk.org/Doxygen/html/ThreadingPage.html
.. _`itk::ImageToImageFilter`: http://www.itk.org/Doxygen/html/classitk_1_1ImageToImageFilter.html
.. _GenerateData(): http://www.itk.org/Doxygen/html/classitk_1_1ImageSource.html#a2f5a02af541f7004f56f66f07c0931f1
.. _ThreadedGenerateData(): http://www.itk.org/Doxygen/html/classitk_1_1ImageSource.html#a75fd7bc20cc74d5afcfc339f742247f3
.. _`itk::DomainThreader`: http://www.itk.org/Doxygen/html/classitk_1_1DomainThreader.html
.. _`itk::MultiThreader`: http://www.itk.org/Doxygen/html/itkMultiThreader_8h_source.html
.. _the implementation of the CannyEdgeDetectionImageFilter: http://itk.org/gitweb?p=ITK.git;a=blob;f=Modules/Filtering/ImageFeature/include/itkCannyEdgeDetectionImageFilter.hxx;h=a10756b741851f8611c2ead7358f6595027a5b48;hb=HEAD#l218
.. _thread-safe: http://en.wikipedia.org/wiki/Thread_safety
.. _thread-local storage: http://en.wikipedia.org/wiki/Thread-local_storage
.. _`itk::SimpleFastMutexLock`: http://www.itk.org/Doxygen/html/classitk_1_1SimpleFastMutexLock.html
.. _default ImageSource implementation of GenerateData(): http://itk.org/gitweb?p=ITK.git;a=blob;f=Modules/Core/Common/include/itkImageSource.hxx;h=b52b4949e68ad311e307c93b0ec25aa93704bdf3;hb=HEAD#l251
.. _BeforeThreadedGenerateData(): http://www.itk.org/Doxygen/html/classitk_1_1ImageSource.html#a3feaf3f80b0339277b2f3502140031f8
.. _AfterThreadedGenerateData(): http://www.itk.org/Doxygen/html/classitk_1_1ImageSource.html#ac1967c5c2e3cbdbf5ae6d1f6c916790d
.. _`implementation of the itk::MinimumMaximumImageFilter`: http://itk.org/gitweb?p=ITK.git;a=blob;f=Modules/Filtering/ImageStatistics/include/itkMinimumMaximumImageFilter.hxx;h=d6e0fca1a404e3507cbcbac3ade68ab6e90706d1;hb=HEAD
.. _data-parallel: http://en.wikipedia.org/wiki/Data_parallelism
.. _`itk::ImageRegion's like ThreadedGenerateData()`: http://www.itk.org/Doxygen/html/classitk_1_1ThreadedImageRegionPartitioner.html
.. _`index ranges in an itk::Array`: http://www.itk.org/Doxygen/html/classitk_1_1ThreadedIndexedContainerPartitioner.html
.. _a range specified by Standard Library iterators: http://www.itk.org/Doxygen/html/classitk_1_1ThreadedIteratorRangePartitioner.html
.. _`itk::ImageSource`: http://www.itk.org/Doxygen/html/classitk_1_1ImageSource.html
.. _friend class: http://en.wikipedia.org/wiki/Friend_class
.. _cell counting example: http://itk.org/ITKExamples/src/Core/Common/DoDataParallelThreading/Documentation.html
