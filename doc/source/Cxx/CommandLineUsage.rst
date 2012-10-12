.. index:: command line usage

.. _Command Line Usage:

Command Line Usage
==================

Description
-----------

This page describes how to interact with the command line

In particular it addresses basic commands in the bash shell

Welcome to Earth!
-----------------

You just opened a terminal in you favorite Linux distribution. A black window
is facing you and a blinking cursor is prompting you for typing a command.

Here are the first commands that you may want to try:

* clear
* date
* echo
* info
* ls
* pwd
* who
* whoami


Video 1
-------

You can see the video of this example at:

   .. youtube:: zrKvaS2WGaQ


Streams and Pipes
-----------------

* echo
* cat
* tac
* rev
* pipes


Video 2
-------

You can see the video of this example at:

   .. youtube:: zY0snYciEZI



Creating Directories
--------------------

* mkdir
* rmdir

The two commands above will create and remove directories in the file system.

Removing Files
--------------

The rm command will remove files and directories from the file system. You must Fear this command, or at least respect it.

* rm
* rm -r

The -r option of the rm command is particularly dangerous. It removes the
content of a directory and all its subdirectories. Normally there is not a way
of undoing this delete. Therefore, you must verify your current location in the
file system before you use this command. Of course, you also want to verify
that you really want to delete that directory and its content.

Our conscience is now clear,
whatever happens to you, remember that we told you so !

Video 3
-------

You can see the video of this example at:

   .. youtube::  C_YoCSvttc0



Copying, Moving, Deleting files
-------------------------------

* cp
* mv
* rm

along with their recursive options, that must be used very carefully since they can be dangerous

* cp -r
* rm -r


Video 4
-------

You can see the video of this example at:

   .. youtube::  jjdRlapJa2w



Moving Through Directories
--------------------------

* pushcd
* popd



Hard Links
----------

Hard links are a way of having a file appear in two directories and to have
alternative filenames for the same content of bytes stored in disk.

* Hard links can only be created for files.
* Hard links can not be created for directories.


Examples

::

  ln  /home/me/directoryA/myFile01.txt   /home/me/directoryB/anotherName.txt

This example creates a second filename "anotherName.txt" in the "directoryB" for
the ''content'' of the file myFile01.txt.

The new filename "anotherName.txt" will link to the content even if the initial
"myFile01.txt" filename is deleted.


Symbolic Links
--------------

* Symbolic Links are a second name that is associated with an existing filename.

* Symbolic links entirely depend on the original filename. If that original
  filename is deleted, then the symbolic link becomes a "dangling" link and it
  is unusable.

* Symbolic links can be created for files and directories.

Examples

::

  ln  -s /home/me/directoryA/myFile01.txt   /home/me/directoryB/anotherName.txt

  ln  -s /home/me/directoryA/myFile01.txt   /home/me/directoryB/

  ln  -s /home/me/directoryA    /home/me/directoryC


* The first example creates an alias name for myFile01.txt in another directory.
* The second example creates a link with the same filename in another directory.
* The third example creates a link to directoryA under the name of directoryC.

The path to the original file or directory must be provided in a form that
makes sense from the point of view of the location of the destination name.
This means that the original name must be specified as one of the following:

* An absolute path, or
* A path relative to the location of the destination name


Listing Files
-------------

* ls


Counting Chars, Words, Lines
----------------------------

* wc


Root Superpowers
----------------

* sudo

Make me a sandwich


Environment Variables
---------------------

* export
* echo
* env


Sorting
-------

* sort


Help Me!
--------

* man
* info

See also
--------

* :ref:`Command Line Arguments`
