cmake_minimum_required(VERSION 3.2)
project(dlibdlibtest VERSION 0.0.1)

include_directories(${PROJECT_BINARY_DIR})

add_executable(dlibtest dlibtest.cpp)

set_target_properties(dlibtest PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

find_package(dlib REQUIRED)
target_link_libraries(dlibtest dlib::dlib)

install(TARGETS dlibtest RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dima.friends@mail.ru)

include(CPack)
