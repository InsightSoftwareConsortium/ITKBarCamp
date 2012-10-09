.. index:: command line arguments

.. _Command Line Arguments:

Command Line Arguments
======================

Description
-----------
  This page describes how to use command line arguments in C++

Example 1
---------

::

    #include <iostream>

    int main( int argc, char * argv [] )
    {
    std::cout << "Number of arguments = " << argc << std::endl;
    for(int i=0; i<argc; i++)
      {
      std::cout << argv[i] << std::endl;
      }
    return 0;
    }

This example takes the list of command line arguments and prints them back to
the terminal.

Note that the list of command line arguments in the array argv includes the
name of the executable itself. This name is passed as the first element of the
array.

Example 2
---------

::

    #include <iostream>
    #include <stdlib.h>

    int main( int argc, char * argv [] )
    {
    std::cout << "Number of arguments = " << argc << std::endl;

    std::cout << "Executable name " << argv[0] << std::endl;
    std::cout << "First argumant  " << argv[1] << std::endl;

    int   i = atoi( argv[1] );
    float f = atof( argv[1] );

    std::cout << "Integer form = " << i << std::endl;
    std::cout << "Float   form = " << f << std::endl;

    return 0;
    }

This example take the first element of the argv array and prints it as the
executable filename. Then it takes the second element of the array, which
corresponds to the first command line argument, and prints it as such.

Finally, it uses the atoi() and atof() functions to illustrates how the command
line argument strings can be converted to numbers that are explicitly of type
int and float.

Video 1
-------

You can see the video of this example at:

   .. youtube:: 3iATEcmhB8w


Example 3
---------

This example illustrates how to do error management when accessing the command
line arguments passed to a program.

::

  #include <iostream>
  #include <cstdlib>

  int main( int argc, char * argv [] )
  {

    std::cout << "Number of arguments = " << argc << std::endl;
    std::cout << "Executable name = " << argv[0] << std::endl;

    int numberOfExpectedArguments = 1;

    if( argc < numberOfExpectedArguments+1 )
      {
      std::cerr << "Error: Missing Arguments" << std::endl;
      std::cerr << "Usage: " << std::endl;
      std::cerr << argv[0] << "  numberOfCows(int) " << std::endl;
      return 1;
      }

    int numberOfCows = atoi( argv[1] );

    std::cout << "Number of cows = " << numberOfCows << std::endl;

    return 0;
  }


Video 2
-------

You can see the video of this example at:

   .. youtube:: rJD6Rr3BCYo

This video includes a quick demonstration on how to use the gdb debugger to
track the source of Segmentation Faults that are the common result of
attempting to access elements outside of the range of an array.

See also
--------

* :ref:`Command Line Usage`
