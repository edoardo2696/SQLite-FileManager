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
include CMakeFiles\Win32Project2.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Win32Project2.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Win32Project2.dir\flags.make

CMakeFiles\Win32Project2.dir\test\UnitTest.cpp.obj: CMakeFiles\Win32Project2.dir\flags.make
CMakeFiles\Win32Project2.dir\test\UnitTest.cpp.obj: ..\test\UnitTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Win32Project2.dir/test/UnitTest.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Win32Project2.dir\test\UnitTest.cpp.obj /FdCMakeFiles\Win32Project2.dir\Win32Project2.pdb /FS -c "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\UnitTest.cpp"
<<

CMakeFiles\Win32Project2.dir\test\UnitTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Win32Project2.dir/test/UnitTest.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\Win32Project2.dir\test\UnitTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\UnitTest.cpp"
<<

CMakeFiles\Win32Project2.dir\test\UnitTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Win32Project2.dir/test/UnitTest.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Win32Project2.dir\test\UnitTest.cpp.s /c "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\test\UnitTest.cpp"
<<

# Object files for target Win32Project2
Win32Project2_OBJECTS = \
"CMakeFiles\Win32Project2.dir\test\UnitTest.cpp.obj"

# External object files for target Win32Project2
Win32Project2_EXTERNAL_OBJECTS =

Win32Project2.lib: CMakeFiles\Win32Project2.dir\test\UnitTest.cpp.obj
Win32Project2.lib: CMakeFiles\Win32Project2.dir\build.make
Win32Project2.lib: CMakeFiles\Win32Project2.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library Win32Project2.lib"
	$(CMAKE_COMMAND) -P CMakeFiles\Win32Project2.dir\cmake_clean_target.cmake
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /lib /nologo /machine:X86 /out:Win32Project2.lib @CMakeFiles\Win32Project2.dir\objects1.rsp 

# Rule to build all files generated by this target.
CMakeFiles\Win32Project2.dir\build: Win32Project2.lib

.PHONY : CMakeFiles\Win32Project2.dir\build

CMakeFiles\Win32Project2.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Win32Project2.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Win32Project2.dir\clean

CMakeFiles\Win32Project2.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug" "C:\Users\Edoardo Luci\Desktop\Elaborato C++\SQLite FileManager\cmake-build-debug\CMakeFiles\Win32Project2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Win32Project2.dir\depend

