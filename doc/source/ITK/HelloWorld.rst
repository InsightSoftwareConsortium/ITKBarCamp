===========
Hello World
===========

Description
###########
  Your first ITK program


Code
####

::

  #include "itkImage.hxx"

  int main()
  {
    typedef itk::Image< char, 2 >  ImageType;
    ImageType::Pointer image = ImageType::New();
    std::cout << "Hello World ITK !" << std::endl;
    return EXIT_SUCCESS;
  }

