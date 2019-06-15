cmake_minimum_required(VERSION 3.2)

project(kkmeans)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})

include_directories(${PROJECT_BINARY_DIR})

include(dlib-19.6/dlib/cmake)

add_executable(kkmeans kkmeans.cpp)

target_link_libraries(kkmeans dlib::dlib)

install(TARGETS kkmeans RUNTIME DESTINATION bin)
install(FILES kkmeans_ex.txt DESTINATION "~")

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dima.friends@mail.ru)

include(CPack)
