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
include Win32Project\test\CMakeFiles\SqliteUnitTest.dir\depend.make

# Include the progress variables for this target.
include Win32Project\test\CMakeFiles\SqliteUnitTest.dir\progress.make

# Include the compile flags for this target's objects.
include Win32Project\test\CMakeFiles\SqliteUnitTest.dir\flags.make

Win32Project\test\CMakeFiles\SqliteUnitTest.dir\SqlUnitTest.cpp.obj: Win32Project\test\CMakeFiles\SqliteUnitTest.dir\flags.make
Win32Project\test\CMakeFiles\SqliteUnitTest.dir\SqlUnitTest.cpp.obj: ..\Win32Project\test\SqlUnitTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Win32Project/test/CMakeFiles/SqliteUnitTest.dir/SqlUnitTest.cpp.obj"
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\CMAKE-~1\WIN32P~1\test
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\SqliteUnitTest.dir\SqlUnitTest.cpp.obj /FdCMakeFiles\SqliteUnitTest.dir\ /FS -c "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\Win32Project\test\SqlUnitTest.cpp"
<<
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\CMAKE-~1

Win32Project\test\CMakeFiles\SqliteUnitTest.dir\SqlUnitTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SqliteUnitTest.dir/SqlUnitTest.cpp.i"
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\CMAKE-~1\WIN32P~1\test
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\SqliteUnitTest.dir\SqlUnitTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\Win32Project\test\SqlUnitTest.cpp"
<<
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\CMAKE-~1

Win32Project\test\CMakeFiles\SqliteUnitTest.dir\SqlUnitTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SqliteUnitTest.dir/SqlUnitTest.cpp.s"
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\CMAKE-~1\WIN32P~1\test
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SqliteUnitTest.dir\SqlUnitTest.cpp.s /c "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\Win32Project\test\SqlUnitTest.cpp"
<<
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\CMAKE-~1

# Object files for target SqliteUnitTest
SqliteUnitTest_OBJECTS = \
"CMakeFiles\SqliteUnitTest.dir\SqlUnitTest.cpp.obj"

# External object files for target SqliteUnitTest
SqliteUnitTest_EXTERNAL_OBJECTS =

Win32Project\test\SqliteUnitTest.exe: Win32Project\test\CMakeFiles\SqliteUnitTest.dir\SqlUnitTest.cpp.obj
Win32Project\test\SqliteUnitTest.exe: Win32Project\test\CMakeFiles\SqliteUnitTest.dir\build.make
Win32Project\test\SqliteUnitTest.exe: Win32Project\test\lib\googletest\gtestd.lib
Win32Project\test\SqliteUnitTest.exe: Win32Project\test\lib\googletest\gtest_maind.lib
Win32Project\test\SqliteUnitTest.exe: Win32Project\test\lib\googletest\gtestd.lib
Win32Project\test\SqliteUnitTest.exe: Win32Project\test\CMakeFiles\SqliteUnitTest.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SqliteUnitTest.exe"
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\CMAKE-~1\WIN32P~1\test
	"C:\Program Files\JetBrains\CLion 2018.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\SqliteUnitTest.dir --manifests  -- C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\SqliteUnitTest.dir\objects1.rsp @<<
 /out:SqliteUnitTest.exe /implib:SqliteUnitTest.lib /pdb:"C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\Win32Project\test\SqliteUnitTest.pdb" /version:0.0  /NODEFAULTLIB:LIBCMTD  /NODEFAULTLIB:libcpmtd /debug /INCREMENTAL /subsystem:console lib\googletest\gtestd.lib lib\googletest\gtest_maind.lib lib\googletest\gtestd.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\CMAKE-~1

# Rule to build all files generated by this target.
Win32Project\test\CMakeFiles\SqliteUnitTest.dir\build: Win32Project\test\SqliteUnitTest.exe

.PHONY : Win32Project\test\CMakeFiles\SqliteUnitTest.dir\build

Win32Project\test\CMakeFiles\SqliteUnitTest.dir\clean:
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\CMAKE-~1\WIN32P~1\test
	$(CMAKE_COMMAND) -P CMakeFiles\SqliteUnitTest.dir\cmake_clean.cmake
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\CMAKE-~1
.PHONY : Win32Project\test\CMakeFiles\SqliteUnitTest.dir\clean

Win32Project\test\CMakeFiles\SqliteUnitTest.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\Win32Project\test" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\Win32Project\test" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\Win32Project\test\CMakeFiles\SqliteUnitTest.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : Win32Project\test\CMakeFiles\SqliteUnitTest.dir\depend
