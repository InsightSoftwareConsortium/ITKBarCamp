#Client maintainer: xiaoxiao.liu@kitware.com
set(CTEST_SITE "xyj.kitware")
set(CTEST_BUILD_NAME "Gentoo-g++-4.6.3-Release")
set(CTEST_BUILD_FLAGS -j4)
set(CTEST_DASHBOARD_ROOT "/home/xiaoxiao/Dashboards")
set(CTEST_TEST_TIMEOUT 240)
set(CTEST_BUILD_CONFIGURATION Release)
set(CTEST_CMAKE_GENERATOR "Unix Makefiles")
set(dashboard_source_name "src/ITK")
set(dashboard_binary_name "bin/ITK/Release")
set(dashboard_model Nightly)

set(dashboard_cache "
BUILD_SHARED_LIBS:BOOL=OFF
BUILD_TESTING:BOOL=ON
BUILD_EXAMPLES:BOOL=ON
MAXIMUM_NUMBER_OF_HEADERS:STRING=1
CMAKE_CXX_COMPILER:PATH=/usr/bin/c++
CMAKE_C_COMPILER:PATH=/usr/bin/gcc
ITK_BUILD_ALL_MODULES:BOOL=ON
ITKV3_COMPATIBILITY:BOOL=ON
Module_ITKDeprecated:BOOL=ON
ITK_USE_REVIEW:BOOL=ON
ITK_COMPUTER_MEMORY_SIZE:STRING=2
")

include(${CTEST_SCRIPT_DIRECTORY}/itk_common.cmake)
