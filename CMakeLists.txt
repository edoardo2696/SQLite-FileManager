cmake_minimum_required(VERSION 3.12)
project(Win32Project2)

set(CMAKE_CXX_STANDARD 11)

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)


include_directories(Win32Project2)
include_directories(Win32Project2/databaselayer/include)
include_directories(Win32Project2/databaselayer/lib/vc_lib)
include_directories(Win32Project2/databaselayer/sqlite/include)
include_directories(Win32Project2/wxActiveRecord)



add_executable(Win32Project2__Copia WIN32
        ${PROJECT_SOURCE_DIR}/Win32Project2/EditGroupDialog.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project2/EditGroupDialog.h
        ${PROJECT_SOURCE_DIR}/Win32Project2/EditElementDialog.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project2/EditElementDialog.h
        ${PROJECT_SOURCE_DIR}/Win32Project2/Group.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project2/Group.h
        ${PROJECT_SOURCE_DIR}/Win32Project2/Element.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project2/Element.h
        ${PROJECT_SOURCE_DIR}/Win32Project2/RecordIDClientData.h
        ${PROJECT_SOURCE_DIR}/Win32Project2/SQLiteTestApp.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project2/SQLiteTestApp.h
        ${PROJECT_SOURCE_DIR}/Win32Project2/SQLiteTestMainFrame.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project2/SQLiteTestMainFrame.h
        ${PROJECT_SOURCE_DIR}/Win32Project2/wxActiveRecord.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project2/wxActiveRecord.h
        ${PROJECT_SOURCE_DIR}/Win32Project2/About.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project2/About.h
        ${PROJECT_SOURCE_DIR}/Win32Project2/SearchElement.cpp
        ${PROJECT_SOURCE_DIR}/Win32Project2/SearchElement.h

        )

target_link_libraries( Win32Project2__Copia
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxbase30ud.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxbase30ud_net.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxbase30ud_xml.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxregexud.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxexpatd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_core.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_adv.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxpngd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxjpegd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxtiffd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxzlibd.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_html.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_gl.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_qa.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_xrc.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_aui.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_propgrid.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_ribbon.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_richtext.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_media.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_stc.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxscintillad.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_webview.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_media.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxmsw30ud_media.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/lib/vc_lib/wxcode_msw28ud_databaselayer_sqlite.lib
        ${PROJECT_SOURCE_DIR}/Win32Project2/databaselayer/sqlite/lib/sqlite3.lib
        )
