cmake_minimum_required(VERSION 3.16)
project(DisorderHandlingSystem)

set(CMAKE_CXX_STANDARD 14)

set(DISORDER_HANDLING_SYSTEM_SRC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/include)

include_directories(${DISORDER_HANDLING_SYSTEM_SRC_INCLUDE_DIR})

add_subdirectory(src)
add_executable(DisorderHandlingSystem main.cpp src/kslack/k_slack.cpp src/include/kslack/k_slack.h src/include/common/define.h src/manager/buffer_size_manager.cpp src/include/manager/buffer_size_manager.h src/manager/statistics_manager.cpp src/include/manager/statistics_manager.h src/synchronizer/synchronizer.cpp src/include/synchronizer/synchronizer.h src/operator/stream_operator.cpp src/include/operator/stream_operator.h src/common/stream.cpp src/include/common/stream.h)
