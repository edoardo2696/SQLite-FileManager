# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Win32Project.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Win32Project.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Win32Project.dir\flags.make

CMakeFiles\Win32Project.dir\Win32Project\SQLiteTestMainFrame.cpp.obj: CMakeFiles\Win32Project.dir\flags.make
CMakeFiles\Win32Project.dir\Win32Project\SQLiteTestMainFrame.cpp.obj: ..\Win32Project\SQLiteTestMainFrame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Win32Project.dir/Win32Project/SQLiteTestMainFrame.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Win32Project.dir\Win32Project\SQLiteTestMainFrame.cpp.obj /FdCMakeFiles\Win32Project.dir\ /FS -c "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\Win32Project\SQLiteTestMainFrame.cpp"
<<

CMakeFiles\Win32Project.dir\Win32Project\SQLiteTestMainFrame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Win32Project.dir/Win32Project/SQLiteTestMainFrame.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\Win32Project.dir\Win32Project\SQLiteTestMainFrame.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\Win32Project\SQLiteTestMainFrame.cpp"
<<

CMakeFiles\Win32Project.dir\Win32Project\SQLiteTestMainFrame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Win32Project.dir/Win32Project/SQLiteTestMainFrame.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Win32Project.dir\Win32Project\SQLiteTestMainFrame.cpp.s /c "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\Win32Project\SQLiteTestMainFrame.cpp"
<<

# Object files for target Win32Project
Win32Project_OBJECTS = \
"CMakeFiles\Win32Project.dir\Win32Project\SQLiteTestMainFrame.cpp.obj"

# External object files for target Win32Project
Win32Project_EXTERNAL_OBJECTS =

Win32Project.exe: CMakeFiles\Win32Project.dir\Win32Project\SQLiteTestMainFrame.cpp.obj
Win32Project.exe: CMakeFiles\Win32Project.dir\build.make
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud_net.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud_xml.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxregexud.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxexpatd.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_core.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_adv.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxpngd.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxjpegd.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxtiffd.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxzlibd.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_html.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_gl.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_qa.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_xrc.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_aui.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_propgrid.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_ribbon.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_richtext.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_media.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_stc.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxscintillad.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_webview.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_media.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_media.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxcode_msw28ud_databaselayer_sqlite.lib
Win32Project.exe: ..\Win32Project\databaselayer\sqlite\lib\sqlite3.lib
Win32Project.exe: Win32Project2.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud_net.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud_xml.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxregexud.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxexpatd.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_core.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_adv.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxpngd.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxjpegd.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxtiffd.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxzlibd.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_html.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_gl.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_qa.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_xrc.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_aui.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_propgrid.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_ribbon.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_richtext.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_media.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_stc.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxscintillad.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_webview.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_media.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_stc.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxscintillad.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_webview.lib
Win32Project.exe: ..\Win32Project\databaselayer\lib\vc_lib\wxcode_msw28ud_databaselayer_sqlite.lib
Win32Project.exe: ..\Win32Project\databaselayer\sqlite\lib\sqlite3.lib
Win32Project.exe: CMakeFiles\Win32Project.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Win32Project.exe"
	"C:\Program Files\JetBrains\CLion 2018.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Win32Project.dir --manifests  -- C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Win32Project.dir\objects1.rsp @<<
 /out:Win32Project.exe /implib:Win32Project.lib /pdb:"C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\Win32Project.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:windows ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud.lib ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud_net.lib ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud_xml.lib ..\Win32Project\databaselayer\lib\vc_lib\wxregexud.lib ..\Win32Project\databaselayer\lib\vc_lib\wxexpatd.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_core.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_adv.lib ..\Win32Project\databaselayer\lib\vc_lib\wxpngd.lib ..\Win32Project\databaselayer\lib\vc_lib\wxjpegd.lib ..\Win32Project\databaselayer\lib\vc_lib\wxtiffd.lib ..\Win32Project\databaselayer\lib\vc_lib\wxzlibd.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_html.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_gl.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_qa.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_xrc.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_aui.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_propgrid.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_ribbon.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_richtext.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_media.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_stc.lib ..\Win32Project\databaselayer\lib\vc_lib\wxscintillad.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_webview.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_media.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_media.lib ..\Win32Project\databaselayer\lib\vc_lib\wxcode_msw28ud_databaselayer_sqlite.lib ..\Win32Project\databaselayer\sqlite\lib\sqlite3.lib Win32Project2.lib ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud.lib ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud_net.lib ..\Win32Project\databaselayer\lib\vc_lib\wxbase30ud_xml.lib ..\Win32Project\databaselayer\lib\vc_lib\wxregexud.lib ..\Win32Project\databaselayer\lib\vc_lib\wxexpatd.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_core.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_adv.lib ..\Win32Project\databaselayer\lib\vc_lib\wxpngd.lib ..\Win32Project\databaselayer\lib\vc_lib\wxjpegd.lib ..\Win32Project\databaselayer\lib\vc_lib\wxtiffd.lib ..\Win32Project\databaselayer\lib\vc_lib\wxzlibd.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_html.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_gl.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_qa.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_xrc.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_aui.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_propgrid.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_ribbon.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_richtext.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_media.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_stc.lib ..\Win32Project\databaselayer\lib\vc_lib\wxscintillad.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_webview.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_media.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_stc.lib ..\Win32Project\databaselayer\lib\vc_lib\wxscintillad.lib ..\Win32Project\databaselayer\lib\vc_lib\wxmsw30ud_webview.lib ..\Win32Project\databaselayer\lib\vc_lib\wxcode_msw28ud_databaselayer_sqlite.lib ..\Win32Project\databaselayer\sqlite\lib\sqlite3.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Win32Project.dir\build: Win32Project.exe

.PHONY : CMakeFiles\Win32Project.dir\build

CMakeFiles\Win32Project.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Win32Project.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Win32Project.dir\clean

CMakeFiles\Win32Project.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\CMakeFiles\Win32Project.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Win32Project.dir\depend
