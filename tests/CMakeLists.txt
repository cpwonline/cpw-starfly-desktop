include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(CPPUNIT REQUIRED cppunit)
include_directories(${CPPUNIT_INCLUDE_DIRS} ${GIOMM_INCLUDE_DIRS})
link_directories(CPPUNIT_LIBRARY_DIRS)

add_executable(test_gen test_gen.cc)
add_test(TestGen test_gen)

target_link_libraries(test_gen ${CPPUNIT_LIBRARIES} cpw_notifications ${GIOMM_LIBRARIES} ${GLIBMM_LIBRARIES})
