# CMakeのバージョンを設定-----
cmake_minimum_required(VERSION 3.13)

# プロジェクト名と使用する言語を設定-----
project(cmake_sample CXX C)

# GoogleTestの"CMakeLists.txt"を配置しているパスを設定-----
set(GTEST_PATH ./gtest/googletest-main)
add_subdirectory(${GTEST_PATH})

# GDBのオプション-----
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")

# GCOVオプション-----
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
set(CMAKE_EXE_FLAGS "${CMAKE_EXE_FLAGS} --coverage")


# PATH設定-----
# include
set(GTEST_INC_PATH ./gtest/googletest-main/googletest/include ./gtest/googletest-main/googlemock/include)
set(TEST_INC_PATH ./test_code)
set(TARGET_INC_PATH ./target)
# lib
set(GTEST_LIB_PATH ./build/lib)

# PATH追加-----
include_directories(${GTEST_INC_PATH} ${TEST_INC_PATH} ${TARGET_INC_PATH})
link_directories(${GTEST_LIB_PATH})

# BUILD-----
add_executable(
	test_sample
	./test_code/test_main.cpp
	./target/sub_func_a.c
	./target/sub_func_b.c
	)
target_link_libraries(test_sample libgtest.a libgmock.a libgtest_main.a pthread)

# gcovのための作法-----
#target_compile_options(test_sample PUBLIC -coverage)
#target_link_options(test_sample PUBLIC -coverage)



