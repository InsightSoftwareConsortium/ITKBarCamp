.. index:: macros

Macros
======

Description
-----------
  This page provides an introduction to the use of macros in C++.

  Macros are typically used in one of the following four ways

  * As a replacement for symbols
  * As logical flags to do selective compilation
  * As on-the-fly code generation
  * As accelerators for function-like operations

  Let's go through them.

As Symbols
----------

Macros can be used as a way of replacing symbols

::

    #include <iostream>

    #define NUMBEROFCOWS 42

    int main()
    {
      std::cout << "Number of Cows = " << NUMBEROFCOWS << std::endl;
      return 0;
    }

The #define command is a pre-processor command and it is used to define the
macro NUMBEROFCOWS by assigning to it the value 42.

In this context, the macro is a simple string replacement operation. It is done
by the C++ preprocessor, just before the code is sent to the compiler. This is
essentially equivalent to doing a search and replace operation with your text
editor.

It is traditional to use UPPERCASE characters for naming a macro, but this is
not a requirement. You should follow the coding style adopted by the project
that you are working on. Developers get really angry when you break their
coding style, and they can be very mean people when they are angry. Follow the
coding style.

In modern C++ programming this usage of macros as symbols is discouraged. The
reason is that the same goal can be achieved with the use of "const" variables,
with the added advantage of type checking. The Macro being a simple text
replacement does not provide that verification of type at compilation time.
That is, in our example above NUMBEROFCOWS can equally be used as an integer, a
float or a string.

The code below illustrates how to achieve the same result with the use of const
typed variables.

::

    #include <iostream>

    const unsigned int NUMBEROFCOWS = 42;

    int main()
    {
      std::cout << "Number of Cows = " << NUMBEROFCOWS << std::endl;
      return 0;
    }

The advantage in this case is that the NUMBEROFCOWS has been explicitly
declared as a positive integer type. Therefore, we get the added convenience of
the compiler helping us to ensure that the NUMBEROFCOWS is only used in
accordance to the rules for managing positive integer numbers. This is very
important, since we know that nobody likes negative Cows.

Video 1
-------

You can see the video of this example at:

   .. youtube:: BAIgTOog1Sg


As Logical Flags
----------------

Macros can be used as logical flags to control conditional compilation of
source code.

::

    #include <iostream>

    int main()
    {
    #ifdef YOU_ARE_IN_THE_US
      std::cout << "Football is the most popular Sport = " << std::endl;
    #else
      std::cout << "Soccer is the most popular Sport = " << std::endl;
    #endif

      return 0;
    }


The definition of the YOU_ARE_IN_THE_US Macro symbol can be passed to the
program in multiple ways.

It can be put in a header file that is then included in the program:

::

    #include <iostream>
    #include "macroDefinitions.h"

    int main()
    {
    #ifdef YOU_ARE_IN_THE_US
      std::cout << "Football is the most popular Sport = " << std::endl;
    #else
      std::cout << "Soccer is the most popular Sport = " << std::endl;
    #endif

      return 0;
    }

In which case the macroDefinitions.h file will contain something like

::

   #define YOU_ARE_IN_THE_US

or

::

   #undef YOU_ARE_IN_THE_US

Another way to pass the macro definition to the code is to put it in the
command line arguments that are given to the compiler as illustrated below

::

  g++  macrosAsLogicalFlags.cpp  -DYOU_ARE_IN_THE_US  -o macrosAsLogicalFlags


This usage of macros is very hard to debug and typically it must be reserved
for system configuration issues. For example, selecting between code that is
written for 32-bits or 64-bits platforms.

The other drawback of this usage of macros is that the source code starts
accumulating sections of code that are rarely compiled and rarely executed.
Such dark corners of the code become shelter for bugs that will later multiply
and take over the world !


Video 2
-------

You can see the video of this example at:

   .. youtube:: TePg_djuDtY

It does not includes footage of the part where bugs take over the world...

As Code Generation
------------------

Macros can be used to generate code on the fly.

This is rather advanced use of macros and you probably should avoid it if you
can.

It takes advantage of the fact that macros are expanded by the pre-processor
and therefore allow you to modify the source code of your program before it
gets to the compiler.

::

    #include <iostream>

    #define PRINT_ARGUMENTS  \
      for(int i=0; i<argc; i++) \
       { \
       std::cout << argv[i] << std::endl; \
       }


    int main( int argc, char * argv [] )
    {
      PRINT_ARGUMENTS;

      return 0;
    }

The C++ preprocessor will expand this code to become:

::

    #include <iostream>

    int main( int argc, char * argv [] )
    {
      for(int i=0; i<argc; i++)
       {
       std::cout << argv[i] << std::endl;
       }

      return 0;
    }

Notice the use of the "\\" at the end of the lines in the macro definition. They
are needed because in principle a Macro definition ends at the end of the line.
Therefore, if we want to write multi-line macros, we need to "escape" the end
of the line character.

This is a way of obtaining a bit of readability in the code, at the expense of
producing code that is VERY VERY HARD to debug an maintain. Use this abundantly
if you hate the team of developers that will maintain the code for the next ten
years... be assured, they will hate you back...   :-)

On the other hand, when used wisely, this can help maintain uniformity in the
source code, and actually facilitate maintenance. This is a very sharp knife,
reserve it for very special cases, but also beware that many projects tend to
use this trick.

Video 3
-------

You can see the video of this example at:

   .. youtube:: aOwjz2WJ2yY



As Accelerated Functions
------------------------

Since macros are expanded by the pre-processor before the code is passed to the
compiler, it is possible to use them as a way of inserting some lines of code
that otherwise should have been put in a function. This is usually called
"inlining". What is interesting about using inlining is the fact that the code
will run faster at execution time because instead of having to invoke a function
and pass arguments and returns values via the stack, the entire process
actually happens as if the lines of code were inserted in place... indeed they
are inserted in place.

::

    #include <iostream>
    #include <cstdlib>


    #define isDivisibleByThree( (x) )  \
      (int)((float)(x)/3.0) == ((float)(x)/3.0) ? 1 : 0;


    int main( int argc, char * argv [] )
    {
      if( argc < 2 )
        {
        std::cerr << "Missing Argument" << std::endl;
        return 1;
        }

      float inputNumber = atof( argv[1] );

      if( isDivisibleByThree( inputNumber ) )
        {
        std::cout << "Is Divisible by 3" << std::endl;
        }
      else
        {
        std::cout << "Is Not Divisible by 3" << std::endl;
        }

      return 0;
    }

In this case the isDivisibleByThree() macro, takes more the look of a function.
It is expanded by replacing the argument into the macro expression and putting
it inline. This is particularly interesting for very simply operations, for
which the overhead of pushing and poping values from the stack will be large
compared to the actual computation performed by the function.

Note that in the definition of the macro we put parenthesis "()" around the arguments of the macro. This is done as a precaution against the confusion that may arise when the macro is called with an expression as an argument, for example:

::

   isDivisibleByThree(3+1);

will be expanded to

::

    (int)((float)(3+1)/3.0) == ((float)(3+1)/3.0) ? 1 : 0;

while, if we have not used the parenthesis precaution, the code will be
expanded to

::

    (int)((float)3+1/3.0) == ((float)3+1/3.0) ? 1 : 0;

and the precedence of operations will not correspond to what we were expecting.


Video 4
-------

You can see the video of this example at:

   .. youtube:: uz_2EVcXm-w
