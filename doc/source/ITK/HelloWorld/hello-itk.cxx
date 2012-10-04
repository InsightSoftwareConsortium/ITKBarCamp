#include "itkImage.h"

int main()
{
  typedef itk::Image< char, 2 >  ImageType;
  ImageType::Pointer image = ImageType::New();
  std::cout << "Hello World ITK !" << std::endl;
  std::cout << image << std::endl;
  return EXIT_SUCCESS;
}
