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
include googletest\CMakeFiles\gtest.dir\depend.make

# Include the progress variables for this target.
include googletest\CMakeFiles\gtest.dir\progress.make

# Include the compile flags for this target's objects.
include googletest\CMakeFiles\gtest.dir\flags.make

googletest\CMakeFiles\gtest.dir\src\gtest-all.cc.obj: googletest\CMakeFiles\gtest.dir\flags.make
googletest\CMakeFiles\gtest.dir\src\gtest-all.cc.obj: ..\googletest\src\gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj"
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1\GOOGLE~1
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\gtest.dir\src\gtest-all.cc.obj /FdCMakeFiles\gtest.dir\gtest.pdb /FS -c "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\googletest\src\gtest-all.cc"
<<
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1

googletest\CMakeFiles\gtest.dir\src\gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1\GOOGLE~1
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\gtest.dir\src\gtest-all.cc.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\googletest\src\gtest-all.cc"
<<
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1

googletest\CMakeFiles\gtest.dir\src\gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1\GOOGLE~1
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\gtest.dir\src\gtest-all.cc.s /c "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\googletest\src\gtest-all.cc"
<<
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles\gtest.dir\src\gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

googletest\gtest.lib: googletest\CMakeFiles\gtest.dir\src\gtest-all.cc.obj
googletest\gtest.lib: googletest\CMakeFiles\gtest.dir\build.make
googletest\gtest.lib: googletest\CMakeFiles\gtest.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library gtest.lib"
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1\GOOGLE~1
	$(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1\GOOGLE~1
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /lib /nologo /machine:X86 /out:gtest.lib @CMakeFiles\gtest.dir\objects1.rsp 
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1

# Rule to build all files generated by this target.
googletest\CMakeFiles\gtest.dir\build: googletest\gtest.lib

.PHONY : googletest\CMakeFiles\gtest.dir\build

googletest\CMakeFiles\gtest.dir\clean:
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1\GOOGLE~1
	$(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
	cd C:\Users\EDOARD~1\Desktop\ELABOR~1\SQLITE~2\test\CMAKE-~1
.PHONY : googletest\CMakeFiles\gtest.dir\clean

googletest\CMakeFiles\gtest.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\googletest" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug\googletest" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\cmake-build-debug\googletest\CMakeFiles\gtest.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : googletest\CMakeFiles\gtest.dir\depend

