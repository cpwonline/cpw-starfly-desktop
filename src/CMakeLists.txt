set(
	CPW_NOTIFICATIONS_SRC
	cpw_notifications.cc
	"${HEADER}/cpw_notifications.h"
)
add_library(
	cpw_notifications SHARED ${CPW_NOTIFICATIONS_SRC}
)

include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(GIOMM REQUIRED giomm-2.4)
include_directories(${GIOMM_INCLUDE_DIRS})
link_directories(GIOMM_LIBRARY_DIRS)

target_link_libraries(cpw_notifications ${GIOMM_LIBRARIES})