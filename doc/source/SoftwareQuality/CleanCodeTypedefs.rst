.. index::
  pair: clean code; typedef

Clean Code: typedef's
=====================

Description
-----------
  We describe why and how to use typedef_'s in C++ development with examples from
  ITK.

Why typedef Usage is Important
--------------------------------

Reason Number 1: Maintainability
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Using typedef_'s instead of explicit types is analogous to using variables
instead of explicit numbers in your code.  If the type used for a certain
purpose need to be changed, then only the typedef line needs to be changed.  If
typedef's are not used, thousands of manual changes to the code may be required
to achieve this simple logical operation.

This advantage of typedefs becomes increasing important when dealing with
complex types that are defined in terms of simple types in a nested way.  This
is common with advanced data structures and templated code.

By abstracting types, typedefs can also decimate the number of characters to
type when coding, which reduces development time.

Reason Number 2: Readability
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

C++ is a strongly typed language.  While this increases the verbosity of the
language, it also provides an opportunity to create more readable code if the
names of the types lend insight into the meaning and intended use of a type.

A typedef also allows types to be collected into higher-level abstractions.
This eases logical comprehension.

How to Use typedef's to Improve Software Quality
------------------------------------------------

Sidebar: The typename Keyword
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

If new to templated C++ code, you may come across confusing compiler errors
related to "dependent types" or "typename's".  In these cases, the C++ typename_
keyword needs to be used.  The typename_ keywords needs to be used for types
that depend on template parameters, so-called qualified (the scope is defined)
dependent types.  For example, if a function is templated
over a pixel type, and an *itk::Image* type is defined with that template parameter, then the typename keyword must be used::

  template< class TPixel >
  void findGremlins( itk::Image< TPixel, 2 > * image )
  {
  typedef itk::Image< TPixel, 2 >        ImageType;
  typedef typename ImageType::IndexType  IndexType;
  ...

If there is not a template, however, the typename keyword should not be used::

  void findGremlins( itk::Image< float, 2 > * image )
  {
  typedef float                          PixelType;
  typedef itk::Image< PixelType, 2 >     ImageType;
  typedef ImageType::IndexType           IndexType;
  ...

Best Practices
~~~~~~~~~~~~~~

Standard naming conventions for typedef's defined within a class allow for reuse
in templated applications.  Some of the standard typedef's defined for all ITK
classes are *Self*, *Superclass*, *Pointer*, and *ConstPointer*.

Use a typedef for each new type created in the code made from a template.
Give the typedef a meaningful, succinct name.

Sometimes, typedefs should also be created for simple types.  Again, a uniquely
identifiable, meaningful name for a type increases maintainablity and
readability.

Exercise
--------

Improve the following code by using typedef's::

  // Create and setup a reader
  typedef itk::ImageFileReader< itk::Image< unsigned char, 2 > >  ReaderType;
  itk::ImageFileReader< itk::Image< unsigned char, 2 > >::Pointer reader =
    itk::ImageFileReader< itk::Image< unsigned char, 2 > >::New();
  reader->SetFileName( argv[1] );

  itk::GradientMagnitudeImageFilter< itk::Image< unsigned char, 2 >,
    itk::Image< float, 2 > >::Pointer edgeStrengthFilter =
    itk::GradientMagnitudeImageFilter< itk::Image< unsigned char, 2 >,
      itk::Image< float, 2 > >::New();
  edgeStrengthFilter->SetInput( reader->GetOutput() );

  itk::ImageFileWriter< itk::Image< float, 2 > >::Pointer writer =
    itk::ImageFileWriter< itk::Image< float, 2 > >::New();
  writer->SetFileName( argv[2] );
  writer->SetInput( edgeStrengthFilter->GetOutput() );
  writer->Update();

Answer::

  const unsigned int Dimension = 2;

  typedef unsigned char                            InputPixelType;
  typedef itk::Image< InputPixelType, Dimension >  InputImageType;

  typedef float                                    OutputPixelType;
  typedef itk::Image< OutputPixelType, Dimension > OutputImageType;

  typedef itk::ImageFileReader< InputImageType >  ReaderType;
  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName( argv[1] );

  typedef itk::GradientMagnitudeImageFilter<
      InputImageType, OutputImageType >  EdgeStrengthFilterType;
  EdgeStrengthFilterType::Pointer edgeStrengthFilter = EdgeStrengthFilterType::New();
  edgeStrengthFilter->SetInput( reader->GetOutput() );

  typedef itk::ImageFileWriter< OutputImageType > WriterType;
  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName( argv[2] );
  writer->SetInput( edgeStrengthFilter->GetOutput() );
  writer->Update();


.. _typedef: http://www.cplusplus.com/doc/tutorial/other_data_types/
.. _typename: http://pages.cs.wisc.edu/~driscoll/typename.html
