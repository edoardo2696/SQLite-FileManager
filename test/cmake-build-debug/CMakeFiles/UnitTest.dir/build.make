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
CMAKE_SOURCE_DIR = "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\UnitTest.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\UnitTest.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\UnitTest.dir\flags.make

CMakeFiles\UnitTest.dir\UnitTest.cpp.obj: CMakeFiles\UnitTest.dir\flags.make
CMakeFiles\UnitTest.dir\UnitTest.cpp.obj: ..\UnitTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UnitTest.dir/UnitTest.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\UnitTest.dir\UnitTest.cpp.obj /FdCMakeFiles\UnitTest.dir\ /FS -c "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\UnitTest.cpp"
<<

CMakeFiles\UnitTest.dir\UnitTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnitTest.dir/UnitTest.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\UnitTest.dir\UnitTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\UnitTest.cpp"
<<

CMakeFiles\UnitTest.dir\UnitTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnitTest.dir/UnitTest.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\UnitTest.dir\UnitTest.cpp.s /c "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\UnitTest.cpp"
<<

# Object files for target UnitTest
UnitTest_OBJECTS = \
"CMakeFiles\UnitTest.dir\UnitTest.cpp.obj"

# External object files for target UnitTest
UnitTest_EXTERNAL_OBJECTS =

UnitTest.exe: CMakeFiles\UnitTest.dir\UnitTest.cpp.obj
UnitTest.exe: CMakeFiles\UnitTest.dir\build.make
UnitTest.exe: googletest\gtest.lib
UnitTest.exe: googletest\gtest_main.lib
UnitTest.exe: googletest\gtest.lib
UnitTest.exe: CMakeFiles\UnitTest.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UnitTest.exe"
	"C:\Program Files\JetBrains\CLion 2018.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\UnitTest.dir --manifests  -- C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\UnitTest.dir\objects1.rsp @<<
 /out:UnitTest.exe /implib:UnitTest.lib /pdb:"C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug\UnitTest.pdb" /version:0.0  /NODEFAULTLIB:LIBCMTD /debug /INCREMENTAL /subsystem:console googletest\gtest.lib googletest\gtest_main.lib Win32Project2.lib sqlite3.lib wxcode_msw28ud_databaselayer_sqlite.lib googletest\gtest.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\UnitTest.dir\build: UnitTest.exe

.PHONY : CMakeFiles\UnitTest.dir\build

CMakeFiles\UnitTest.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\UnitTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles\UnitTest.dir\clean

CMakeFiles\UnitTest.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug\CMakeFiles\UnitTest.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\UnitTest.dir\depend

