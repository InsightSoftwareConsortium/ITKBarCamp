.. index:: ! hello world

Hello World
===========

Description
-----------
  Your first ITK program.

Code
----

*hello-itk.cxx*::

  #include "itkImage.h"

  int main()
  {
    typedef itk::Image< char, 2 >  ImageType;
    ImageType::Pointer image = ImageType::New();
    std::cout << "Hello World ITK !" << std::endl;
    std::cout << image << std::endl;
    return EXIT_SUCCESS;
  }

*CMakeLists.txt*:

.. code-block:: cmake

  cmake_minimum_required( VERSION 2.8 )
  enable_testing()

  find_package( ITK REQUIRED )
  include( ${ITK_USE_FILE} )

  add_executable( hello-itk hello-itk.cxx )
  target_link_libraries( hello-itk ${ITK_LIBRARIES} )
  add_test( hello-itk-test hello-itk )

Video for Ubuntu 12.04.1 with GCC and Eclipse
---------------------------------------------

.. youtube:: VfB6ue6HLMA
