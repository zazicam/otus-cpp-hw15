cmake_minimum_required(VERSION 2.8.12)

project(kkmeans)

include(dlib-19.6/dlib/cmake)

add_executable(kkmeans kkmeans.cpp)

target_link_libraries(kkmeans dlib::dlib)

install(TARGETS kkmeans RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dima.friends@mail.ru)

include(CPack)
