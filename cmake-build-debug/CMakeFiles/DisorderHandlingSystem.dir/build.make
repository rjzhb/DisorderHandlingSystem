# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rjzhb/Project/DisorderHandlingSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DisorderHandlingSystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DisorderHandlingSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DisorderHandlingSystem.dir/flags.make

CMakeFiles/DisorderHandlingSystem.dir/main.cpp.o: CMakeFiles/DisorderHandlingSystem.dir/flags.make
CMakeFiles/DisorderHandlingSystem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DisorderHandlingSystem.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisorderHandlingSystem.dir/main.cpp.o -c /home/rjzhb/Project/DisorderHandlingSystem/main.cpp

CMakeFiles/DisorderHandlingSystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisorderHandlingSystem.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DisorderHandlingSystem/main.cpp > CMakeFiles/DisorderHandlingSystem.dir/main.cpp.i

CMakeFiles/DisorderHandlingSystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisorderHandlingSystem.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DisorderHandlingSystem/main.cpp -o CMakeFiles/DisorderHandlingSystem.dir/main.cpp.s

CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.o: CMakeFiles/DisorderHandlingSystem.dir/flags.make
CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.o: ../src/kslack/k_slack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.o -c /home/rjzhb/Project/DisorderHandlingSystem/src/kslack/k_slack.cpp

CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DisorderHandlingSystem/src/kslack/k_slack.cpp > CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.i

CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DisorderHandlingSystem/src/kslack/k_slack.cpp -o CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.s

CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.o: CMakeFiles/DisorderHandlingSystem.dir/flags.make
CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.o: ../src/manager/buffer_size_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.o -c /home/rjzhb/Project/DisorderHandlingSystem/src/manager/buffer_size_manager.cpp

CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DisorderHandlingSystem/src/manager/buffer_size_manager.cpp > CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.i

CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DisorderHandlingSystem/src/manager/buffer_size_manager.cpp -o CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.s

CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.o: CMakeFiles/DisorderHandlingSystem.dir/flags.make
CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.o: ../src/manager/statistics_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.o -c /home/rjzhb/Project/DisorderHandlingSystem/src/manager/statistics_manager.cpp

CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DisorderHandlingSystem/src/manager/statistics_manager.cpp > CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.i

CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DisorderHandlingSystem/src/manager/statistics_manager.cpp -o CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.s

CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.o: CMakeFiles/DisorderHandlingSystem.dir/flags.make
CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.o: ../src/synchronizer/synchronizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.o -c /home/rjzhb/Project/DisorderHandlingSystem/src/synchronizer/synchronizer.cpp

CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DisorderHandlingSystem/src/synchronizer/synchronizer.cpp > CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.i

CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DisorderHandlingSystem/src/synchronizer/synchronizer.cpp -o CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.s

CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.o: CMakeFiles/DisorderHandlingSystem.dir/flags.make
CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.o: ../src/operator/stream_operator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.o -c /home/rjzhb/Project/DisorderHandlingSystem/src/operator/stream_operator.cpp

CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DisorderHandlingSystem/src/operator/stream_operator.cpp > CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.i

CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DisorderHandlingSystem/src/operator/stream_operator.cpp -o CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.s

CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.o: CMakeFiles/DisorderHandlingSystem.dir/flags.make
CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.o: ../src/common/stream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.o -c /home/rjzhb/Project/DisorderHandlingSystem/src/common/stream.cpp

CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DisorderHandlingSystem/src/common/stream.cpp > CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.i

CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DisorderHandlingSystem/src/common/stream.cpp -o CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.s

CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.o: CMakeFiles/DisorderHandlingSystem.dir/flags.make
CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.o: ../src/profiler/tuple_productivity_profiler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.o -c /home/rjzhb/Project/DisorderHandlingSystem/src/profiler/tuple_productivity_profiler.cpp

CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DisorderHandlingSystem/src/profiler/tuple_productivity_profiler.cpp > CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.i

CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DisorderHandlingSystem/src/profiler/tuple_productivity_profiler.cpp -o CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.s

# Object files for target DisorderHandlingSystem
DisorderHandlingSystem_OBJECTS = \
"CMakeFiles/DisorderHandlingSystem.dir/main.cpp.o" \
"CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.o" \
"CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.o" \
"CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.o" \
"CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.o" \
"CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.o" \
"CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.o" \
"CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.o"

# External object files for target DisorderHandlingSystem
DisorderHandlingSystem_EXTERNAL_OBJECTS =

DisorderHandlingSystem: CMakeFiles/DisorderHandlingSystem.dir/main.cpp.o
DisorderHandlingSystem: CMakeFiles/DisorderHandlingSystem.dir/src/kslack/k_slack.cpp.o
DisorderHandlingSystem: CMakeFiles/DisorderHandlingSystem.dir/src/manager/buffer_size_manager.cpp.o
DisorderHandlingSystem: CMakeFiles/DisorderHandlingSystem.dir/src/manager/statistics_manager.cpp.o
DisorderHandlingSystem: CMakeFiles/DisorderHandlingSystem.dir/src/synchronizer/synchronizer.cpp.o
DisorderHandlingSystem: CMakeFiles/DisorderHandlingSystem.dir/src/operator/stream_operator.cpp.o
DisorderHandlingSystem: CMakeFiles/DisorderHandlingSystem.dir/src/common/stream.cpp.o
DisorderHandlingSystem: CMakeFiles/DisorderHandlingSystem.dir/src/profiler/tuple_productivity_profiler.cpp.o
DisorderHandlingSystem: CMakeFiles/DisorderHandlingSystem.dir/build.make
DisorderHandlingSystem: CMakeFiles/DisorderHandlingSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable DisorderHandlingSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DisorderHandlingSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DisorderHandlingSystem.dir/build: DisorderHandlingSystem

.PHONY : CMakeFiles/DisorderHandlingSystem.dir/build

CMakeFiles/DisorderHandlingSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DisorderHandlingSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DisorderHandlingSystem.dir/clean

CMakeFiles/DisorderHandlingSystem.dir/depend:
	cd /home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rjzhb/Project/DisorderHandlingSystem /home/rjzhb/Project/DisorderHandlingSystem /home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug /home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug /home/rjzhb/Project/DisorderHandlingSystem/cmake-build-debug/CMakeFiles/DisorderHandlingSystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DisorderHandlingSystem.dir/depend

