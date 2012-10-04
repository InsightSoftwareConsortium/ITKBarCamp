cmake_minimum_required(VERSION 2.8)

find_package(ITK REQUIRED )
include(${USE_ITK_FILE})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(BasicVideoFiltering
  BasicVideoFiltering.cxx )
target_link_libraries(BasicVideoFiltering
  ${ITK_LIBRARIES} ${OpenCV_LIBS})
