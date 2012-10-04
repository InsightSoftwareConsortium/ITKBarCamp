  cmake_minimum_required( VERSION 2.8 )
  enable_testing()

  find_package( ITK REQUIRED )
  include( ${ITK_USE_FILE} )

  add_executable( hello-itk hello-itk.cxx )
  target_link_libraries( hello-itk ${ITK_LIBRARIES} )
  add_test( hello-itk-test hello-itk )
