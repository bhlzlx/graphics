cmake_minimum_required (VERSION 2.6)

project( script )

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

add_library( lua
					${3RD_SRC}/lua/lapi.c
					${3RD_SRC}/lua/lauxlib.c
					${3RD_SRC}/lua/lbaselib.c
					${3RD_SRC}/lua/lbitlib.c
					${3RD_SRC}/lua/lcode.c
					${3RD_SRC}/lua/lcorolib.c
					${3RD_SRC}/lua/lctype.c
					${3RD_SRC}/lua/ldblib.c
					${3RD_SRC}/lua/ldebug.c
					${3RD_SRC}/lua/ldo.c
					${3RD_SRC}/lua/ldump.c
					${3RD_SRC}/lua/lfunc.c
					${3RD_SRC}/lua/lgc.c
					${3RD_SRC}/lua/linit.c
					${3RD_SRC}/lua/liolib.c
					${3RD_SRC}/lua/llex.c
					${3RD_SRC}/lua/lmathlib.c
					${3RD_SRC}/lua/lmem.c
					${3RD_SRC}/lua/loadlib.c
					${3RD_SRC}/lua/lobject.c
					${3RD_SRC}/lua/lopcodes.c
					${3RD_SRC}/lua/loslib.c
					${3RD_SRC}/lua/lparser.c
					${3RD_SRC}/lua/lstate.c
					${3RD_SRC}/lua/lstring.c
					${3RD_SRC}/lua/lstrlib.c
					${3RD_SRC}/lua/ltable.c
					${3RD_SRC}/lua/ltablib.c
					${3RD_SRC}/lua/ltm.c
					${3RD_SRC}/lua/lua.c
					${3RD_SRC}/lua/luac.c
					${3RD_SRC}/lua/lundump.c
					${3RD_SRC}/lua/lvm.c
					${3RD_SRC}/lua/lzio.c
)

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
					${OW_SRC}/script/scriptengine.cpp
)

add_executable( script
					${PROJECT_SOURCE_DIR}/main.cpp
)

target_link_libraries( script
								ow
								lua
								png
								z
								gdi32 opengl32
								freetype
								iconv
								openal32
								ogg.dll
								vorbisfile.dll
)

install (TARGETS script DESTINATION bin)
