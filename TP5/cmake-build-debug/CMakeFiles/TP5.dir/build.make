# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\chesn\CLionProjects\TP5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\chesn\CLionProjects\TP5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TP5.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/TP5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP5.dir/flags.make

CMakeFiles/TP5.dir/main.c.obj: CMakeFiles/TP5.dir/flags.make
CMakeFiles/TP5.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chesn\CLionProjects\TP5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TP5.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TP5.dir\main.c.obj -c C:\Users\chesn\CLionProjects\TP5\main.c

CMakeFiles/TP5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP5.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\chesn\CLionProjects\TP5\main.c > CMakeFiles\TP5.dir\main.c.i

CMakeFiles/TP5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP5.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\chesn\CLionProjects\TP5\main.c -o CMakeFiles\TP5.dir\main.c.s

CMakeFiles/TP5.dir/TP5.c.obj: CMakeFiles/TP5.dir/flags.make
CMakeFiles/TP5.dir/TP5.c.obj: ../TP5.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chesn\CLionProjects\TP5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TP5.dir/TP5.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TP5.dir\TP5.c.obj -c C:\Users\chesn\CLionProjects\TP5\TP5.c

CMakeFiles/TP5.dir/TP5.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP5.dir/TP5.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\chesn\CLionProjects\TP5\TP5.c > CMakeFiles\TP5.dir\TP5.c.i

CMakeFiles/TP5.dir/TP5.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP5.dir/TP5.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\chesn\CLionProjects\TP5\TP5.c -o CMakeFiles\TP5.dir\TP5.c.s

CMakeFiles/TP5.dir/tableau.c.obj: CMakeFiles/TP5.dir/flags.make
CMakeFiles/TP5.dir/tableau.c.obj: ../tableau.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chesn\CLionProjects\TP5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TP5.dir/tableau.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TP5.dir\tableau.c.obj -c C:\Users\chesn\CLionProjects\TP5\tableau.c

CMakeFiles/TP5.dir/tableau.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP5.dir/tableau.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\chesn\CLionProjects\TP5\tableau.c > CMakeFiles\TP5.dir\tableau.c.i

CMakeFiles/TP5.dir/tableau.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP5.dir/tableau.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\chesn\CLionProjects\TP5\tableau.c -o CMakeFiles\TP5.dir\tableau.c.s

# Object files for target TP5
TP5_OBJECTS = \
"CMakeFiles/TP5.dir/main.c.obj" \
"CMakeFiles/TP5.dir/TP5.c.obj" \
"CMakeFiles/TP5.dir/tableau.c.obj"

# External object files for target TP5
TP5_EXTERNAL_OBJECTS =

TP5.exe: CMakeFiles/TP5.dir/main.c.obj
TP5.exe: CMakeFiles/TP5.dir/TP5.c.obj
TP5.exe: CMakeFiles/TP5.dir/tableau.c.obj
TP5.exe: CMakeFiles/TP5.dir/build.make
TP5.exe: CMakeFiles/TP5.dir/linklibs.rsp
TP5.exe: CMakeFiles/TP5.dir/objects1.rsp
TP5.exe: CMakeFiles/TP5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\chesn\CLionProjects\TP5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable TP5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TP5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP5.dir/build: TP5.exe
.PHONY : CMakeFiles/TP5.dir/build

CMakeFiles/TP5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TP5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TP5.dir/clean

CMakeFiles/TP5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\chesn\CLionProjects\TP5 C:\Users\chesn\CLionProjects\TP5 C:\Users\chesn\CLionProjects\TP5\cmake-build-debug C:\Users\chesn\CLionProjects\TP5\cmake-build-debug C:\Users\chesn\CLionProjects\TP5\cmake-build-debug\CMakeFiles\TP5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP5.dir/depend
