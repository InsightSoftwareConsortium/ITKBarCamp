.. index:: command line arguments

Command Line Arguments
======================

Description
-----------
  This page describes how to use command line arguments in C++

Examples
--------

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

Examples
--------

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

Video
-----

You can see the video of this example at:

   .. youtube:: 3iATEcmhB8w
