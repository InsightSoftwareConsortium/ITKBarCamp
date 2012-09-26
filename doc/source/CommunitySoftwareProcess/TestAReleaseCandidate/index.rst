.. index:: release candidate, rc

Test a Release Candidate
========================

Description
-----------
  Release candidates (RC's), or pre-release announcements, are intended to allow the
  community to test changes, provide feedback, and make improvements before the
  final release.  This session describes how to test and provide feedback for an
  RC.

Recorded Hangout
----------------

.. youtube:: -QNJ1EDsOV8

Getting the code
----------------

Release candidates are distributed using the revision control system, Git_.  Git
must be downloaded and installed.  To obtain the source code, clone the
repository in a Git shell::

  git clone git://itk.org/ITK.git
  cd ITK

Next, checkout the revision identifying the release candidate.  This revision is
identified in the release candidate announcement sent to the mailing list.  It
will be a git tag for a minor version release candidate or the *release* branch
for patch version pre-release.  For example::

  git checkout v4.2rc04

or::

  git checkout -b release origin/release

What to do with the code
------------------------

Build the code with the compiler you use for development.  Use the same CMake
options that you use in development.  Build and test the programs you have
written that use ITK or the projects that you use that depend on ITK.  Report
any issues found to the mailing lists and issue tracker.

Perform an Experimental submission to the dashboard with::

  ctest -D Experimental

on Linux/Mac, or::

  ctest -D Experimental -C Release

for Visual Studio.  This command must be executed from the top of the build tree.

After running an Experimental submission, summarize your results in a reply to
the RC announcement thread on the mailing list.


.. _Git: http://git-scm.com/
