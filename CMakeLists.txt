cmake_minimum_required(VERSION 3.12)
project(Win32Project)

set(CMAKE_CXX_STANDARD 11)

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

include_directories(Win32Project/googletest-master/googletest/include Win32Project/googletest-master/googletest)
include_directories(Win32Project)
include_directories(Win32Project/databaselayer/include)
include_directories(Win32Project/databaselayer/lib/vc_lib)
include_directories(Win32Project/databaselayer/sqlite/include)
include_directories(Win32Project/wxActiveRecord)


add_executable(Win32Project WIN32
        ${PROJECT_SOURCE_DIR}/Win32Project/SQLiteTestMainFrame.cpp
        )
add_library(Win32Project2
        ${PROJECT_SOURCE_DIR}/Win32Project/EditGroupDialog.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project/EditGroupDialog.h
        ${PROJECT_SOURCE_DIR}/Win32Project/EditElementDialog.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project/EditElementDialog.h
        ${PROJECT_SOURCE_DIR}/Win32Project/Group.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project/Group.h
        ${PROJECT_SOURCE_DIR}/Win32Project/Gcode.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project/Gcode.h
        ${PROJECT_SOURCE_DIR}/Win32Project/Element.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project/Element.h
        ${PROJECT_SOURCE_DIR}/Win32Project/RecordIDClientData.h
        ${PROJECT_SOURCE_DIR}/Win32Project/SqlUnitTest.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project/SqlUnitTest.h
        ${PROJECT_SOURCE_DIR}/Win32Project/SQLiteTestMainFrame.h
        ${PROJECT_SOURCE_DIR}/Win32Project/wxActiveRecord.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project/wxActiveRecord.h
        ${PROJECT_SOURCE_DIR}/Win32Project/About.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project/About.h
        ${PROJECT_SOURCE_DIR}/Win32Project/EditGcodeDialog.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project/EditGcodeDialog.h)


target_link_libraries( Win32Project
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxbase30ud.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxbase30ud_net.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxbase30ud_xml.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxregexud.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxexpatd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_core.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_adv.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxpngd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxjpegd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxtiffd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxzlibd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_html.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_gl.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_qa.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_xrc.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_aui.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_propgrid.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_ribbon.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_richtext.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_media.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_stc.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxscintillad.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_webview.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_media.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_media.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxcode_msw28ud_databaselayer_sqlite.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/sqlite/lib/sqlite3.lib
        )

target_link_libraries(Win32Project2
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxbase30ud.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxbase30ud_net.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxbase30ud_xml.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxregexud.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxexpatd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_core.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_adv.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxpngd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxjpegd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxtiffd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxzlibd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_html.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_gl.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_qa.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_xrc.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_aui.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_propgrid.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_ribbon.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_richtext.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_media.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_stc.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxscintillad.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_webview.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_media.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxmsw30ud_media.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/lib/vc_lib/wxcode_msw28ud_databaselayer_sqlite.lib
        ${PROJECT_SOURCE_DIR}/Win32Project/databaselayer/sqlite/lib/sqlite3.lib
        )

target_link_libraries(Win32Project Win32Project2)


