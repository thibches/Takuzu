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
CMAKE_SOURCE_DIR = C:\Users\chesn\CLionProjects\Takuzu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\chesn\CLionProjects\Takuzu\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Takuzu.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Takuzu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Takuzu.dir/flags.make

CMakeFiles/Takuzu.dir/main.c.obj: CMakeFiles/Takuzu.dir/flags.make
CMakeFiles/Takuzu.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chesn\CLionProjects\Takuzu\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Takuzu.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Takuzu.dir\main.c.obj -c C:\Users\chesn\CLionProjects\Takuzu\main.c

CMakeFiles/Takuzu.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Takuzu.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\chesn\CLionProjects\Takuzu\main.c > CMakeFiles\Takuzu.dir\main.c.i

CMakeFiles/Takuzu.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Takuzu.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\chesn\CLionProjects\Takuzu\main.c -o CMakeFiles\Takuzu.dir\main.c.s

CMakeFiles/Takuzu.dir/Fonctions.c.obj: CMakeFiles/Takuzu.dir/flags.make
CMakeFiles/Takuzu.dir/Fonctions.c.obj: ../Fonctions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chesn\CLionProjects\Takuzu\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Takuzu.dir/Fonctions.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Takuzu.dir\Fonctions.c.obj -c C:\Users\chesn\CLionProjects\Takuzu\Fonctions.c

CMakeFiles/Takuzu.dir/Fonctions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Takuzu.dir/Fonctions.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\chesn\CLionProjects\Takuzu\Fonctions.c > CMakeFiles\Takuzu.dir\Fonctions.c.i

CMakeFiles/Takuzu.dir/Fonctions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Takuzu.dir/Fonctions.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\chesn\CLionProjects\Takuzu\Fonctions.c -o CMakeFiles\Takuzu.dir\Fonctions.c.s

# Object files for target Takuzu
Takuzu_OBJECTS = \
"CMakeFiles/Takuzu.dir/main.c.obj" \
"CMakeFiles/Takuzu.dir/Fonctions.c.obj"

# External object files for target Takuzu
Takuzu_EXTERNAL_OBJECTS =

Takuzu.exe: CMakeFiles/Takuzu.dir/main.c.obj
Takuzu.exe: CMakeFiles/Takuzu.dir/Fonctions.c.obj
Takuzu.exe: CMakeFiles/Takuzu.dir/build.make
Takuzu.exe: CMakeFiles/Takuzu.dir/linklibs.rsp
Takuzu.exe: CMakeFiles/Takuzu.dir/objects1.rsp
Takuzu.exe: CMakeFiles/Takuzu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\chesn\CLionProjects\Takuzu\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Takuzu.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Takuzu.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Takuzu.dir/build: Takuzu.exe
.PHONY : CMakeFiles/Takuzu.dir/build

CMakeFiles/Takuzu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Takuzu.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Takuzu.dir/clean

CMakeFiles/Takuzu.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\chesn\CLionProjects\Takuzu C:\Users\chesn\CLionProjects\Takuzu C:\Users\chesn\CLionProjects\Takuzu\cmake-build-debug C:\Users\chesn\CLionProjects\Takuzu\cmake-build-debug C:\Users\chesn\CLionProjects\Takuzu\cmake-build-debug\CMakeFiles\Takuzu.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Takuzu.dir/depend

