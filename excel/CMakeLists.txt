cmake_minimum_required (VERSION 2.6)

project( excel )

set ( LIBOW_VERSION_MAJOR_VERSION_MAJAR 1)
set ( LIBOW_VERSION_MAJOR_VERSION_MINOR 0)

set ( OW_SRC "${PROJECT_SOURCE_DIR}/../src/ow")
set ( 3RD_SRC "${PROJECT_SOURCE_DIR}/../src/3rd")
set ( APP_SRC "${PROJECT_SOURCE_DIR}/app")
set ( 3RD_INC "E:/tdmgcclib/include")
set ( 3RD_LIB "E:/tdmgcclib/lib")

configure_file(
	"${PROJECT_SOURCE_DIR}/../src/libowconf.h.in"
	"${PROJECT_SOURCE_DIR}/../src/libowconf.h"
)

include_directories(
	"${OW_SRC}"
	"${3RD_SRC}"
	"${APP_SRC}"
	"${3RD_INC}"
	"${3RD_INC}/freetype"
)

link_directories(
	"${3RD_LIB}"
)

set(CMAKE_BUILD_TYPE "Debug")


if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -g -Wall -Wno-unused-variable")
else( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        set(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -O2")
endif( CMAKE_BUILD_TYPE STREQUAL "Debug" )

message("Build Type:" ${CMAKE_BUILD_TYPE} ${CMAKE_CXX_FLAGS})

add_library( ow
					${OW_SRC}/file/owfile.cpp
					${OW_SRC}/zip/owzip.cpp
					${OW_SRC}/package/owpackage.cpp
					${OW_SRC}/package/package_common.cpp
					${OW_SRC}/cmn/owcmn.cpp
					${OW_SRC}/cmn/owstring.cpp
					${OW_SRC}/cmn/resources.cpp
					${OW_SRC}/cmn/log/logger.cpp
					${OW_SRC}/memory/memory.cpp
					${OW_SRC}/excel/excel.cpp
					${OW_SRC}/excel/excel_def_imp.cpp
					${OW_SRC}/crypto/md5.cpp
					${OW_SRC}/buffer/buffer.cpp
					${OW_SRC}/audio/owaeplayer.cpp
					${OW_SRC}/audio/owaudio.cpp
					${OW_SRC}/archive/owarchive.cpp
)

add_executable( excel
					${PROJECT_SOURCE_DIR}/main.cpp
)

target_link_libraries( excel
								ow
								z
								iconv
)

install (TARGETS excel DESTINATION bin)
