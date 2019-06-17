cmake_minimum_required(VERSION 3.2)

project(kkmeans)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})

include_directories(${PROJECT_BINARY_DIR})

include(dlib-19.6/dlib/cmake)

add_executable(kkmeans kkmeans.cpp)

target_link_libraries(kkmeans dlib::dlib)

add_executable(visualize 
	visualize/visualize.cpp 
	visualize/png_image.cpp
)

set_target_properties(visualize PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})
target_link_libraries(visualize ${PNG_LIBRARY})

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION /usr/share/kkmeans/)
install(TARGETS kkmeans RUNTIME DESTINATION bin)
install(TARGETS visualize RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dima.friends@mail.ru)

include(CPack)
