.. index::
  pair: release announcement, v4.2.1

What's New in Release 4.2.1
===========================

Description
-----------
  A summary of what is new in the 4.2.1 patch release.

Summary
-------

Release 4.2.1 was a bugfix/patch release.  This release addressed some critical
build and performance issues.

* Important performance gains were the result of efforts by community members
  Bradley Lowekamp and Kent Williams through the removal of filter
  GetInput/GetOutput calls in inner loops.
* Compilation errors were fixed for Visual Studio 2012.
* A number of CMake/WrapITK issues were addressed to improve Python wrapping on
  Windows.
* There were also other assorted fixes.
* The next minor feature release, v4.3.0, is scheduled for December.

List of commits
---------------

::

  Bradley Lowekamp (5):
        COMP: fixing error when instatiated with image of double
        PERF: remove per sample allocation, use per-thread structure
        BUG: prevent static initialization fiasco during factory registration
        BUG: fix writing a corrupt meta image header from unknown metadata
        BUG: fix for overlay functor for llvm optimization bug

  Cory Quammen (1):
        BUG: Added missing include <algorithm>

  Hans Johnson (3):
        BUG: Test harness gave false positives
        BUG: Remove duplicate file in wrong place
        COMP: Remove unnecessary const_cast.

  Ho Cheung (2):
        COMP: Add "#include <functional>" to classes for VS2012
        PERF: Fix usage of ElementAt in PolyLineParametricPath to use const version

  Kent Williams (2):
        PERF: Pull expensive GetInput/GetOutput calls out of inner loops
        COMP: propogate compiler selection & flags to FFTW build

  Kris Zygmunt (1):
        BUG: GPU tests sometimes fails

  Matthew McCormick (4):
        BUG: Fix GCC_XML and SWIG ExternalProject dependencies.
        BUG: Fix WrapITK GCCXML ExternalProject dependency.
        COMP: Make sure the VC script gets executed after gccxml installation.
        BUG: Fix multi-object MetaIO reading for ASCII MetaVesselTube.

  Matthias Seise (1):
        COMP: Compile wrapITK for python2.7,64bit on windows

  Willi Huber (1):
        COMP: WrapITK generates non-unique typedefs in FFT submodule

Video
-----

.. youtube:: lJF2jIlEM8c
