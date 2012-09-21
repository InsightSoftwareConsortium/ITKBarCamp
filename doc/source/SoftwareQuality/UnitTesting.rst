============
Unit Testing
============

Description
###########
  This page provides a walk through practical Unit Testing.


First: Write the Test for an empty class
########################################

Here is the test for a Calculator class.

::

    #include <iostream>
    #include "Calculator.hxx"

    int main()
    {
      Calculator calc;
      return 0;
    }


Second: Write The class with no methods
#######################################

Put the following in an file with extension .hxx, called Calculator.hxx

::

   class Calculator
   {
   public:

   private:

   };


