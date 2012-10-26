.. index:: ! module construction

How to construct an ITK module
==================================================

Description
-----------
  * Modularized ITK v4
  * Modularization are done by CMake magics
  * Key CMake code to construct an ITK module

More details about modularization, please refer to  the wiki page:
      http://www.itk.org/Wiki/ITK_Release_4/Modularization

Module template
---------------
   Here is a template module to download (thanks to Bradley Lowekamp):
      git clone https://github.com/blowekamp/itkExternalTemplate.git


Code
----

*CMakeLists.txt*

.. literalinclude:: CMakeLists.txt
  :language: cmake

*itk-module.cmake*:

.. literalinclude:: itk-module.cmake
  :language: cmake

*src/CMakeLists.txt*

.. literalinclude:: src/CMakeLists.txt
  :language: cmake

*test/CMakeLists.txt*

.. literalinclude:: test/CMakeLists.txt
  :language: cmake

Video
-----

.. youtube:: 3ALPKujL0Gk
