cmake_minimum_required(VERSION 3.12)

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

set(CMAKE_STATIC "-static-libgcc -static-libstdc++ -static")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_STATIC}" )
set(CMAKE_CXX_FLAGS "-D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING" )
add_subdirectory(./googletest)

set(gtest_SOURCE_DIR, ./googletest)
set(gtest_force_shared_crt ON CACHE BOOL "msvcrt.dll" FORCE)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(../Win32Project)
include_directories(../Win32Project/databaselayer/include)
include_directories(../Win32Project/databaselayer/lib/vc_lib)
include_directories(../Win32Project2/databaselayer/sqlite/lib)
include_directories(../Win32Project/databaselayer/sqlite/include)
include_directories(../Win32Project/wxActiveRecord)


set(CMAKE_EXE_LINKER_FLAGS
        "/NODEFAULTLIB:LIBCMTD")
set(TEST_SOURCE_FILES UnitTest.cpp)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

enable_testing()


add_executable(UnitTest ${TEST_SOURCE_FILES})
target_link_libraries(UnitTest gtest gtest_main Win32Project2 sqlite3 wxcode_msw28ud_databaselayer_sqlite)