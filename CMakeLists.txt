cmake_minimum_required(VERSION 3.2)

project(kkmeans VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

include_directories(${PROJECT_BINARY_DIR})

include(${CMAKE_CURRENT_SOURCE_DIR}/dlib-19.6/dlib/cmake)

add_executable(kkmeans kkmeans.cpp)

target_link_libraries(kkmeans dlib::dlib)

add_executable(visualize 
	visualize.cpp 
	png_image.cpp
	png_image.hpp
)

set_target_properties(visualize PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})
target_link_libraries(visualize ${PNG_LIBRARY})

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data 
	DESTINATION /usr/share/kkmeans/
)

install(TARGETS kkmeans RUNTIME DESTINATION bin)
install(TARGETS visualize RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dima.friends@mail.ru)

include(CPack)
