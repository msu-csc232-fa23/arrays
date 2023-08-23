cmake_minimum_required(VERSION 3.16.3-3.24.2)
project(ice01)

if (CMAKE_VERSION GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

# Set compiler flags based on environment
if (MSVC)
    # Force to always compile with W4
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif ()
    message("Compiler: MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /std:c++14")
elseif (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    message("Compiler: gnucc or gnucxx")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -g")
elseif((CMAKE_C_COMPILER_ID MATCHES "Clang") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    message("Compiler: Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -g -std=c++14")
endif ()

# echo CMAKE_CXX_FLAGS
message("CMAKE_CXX_FLAGS =${CMAKE_CXX_FLAGS}")

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)

# Source sets for targets
set(SRC_MAIN_FILES src/main/cpp/main.cpp)
set(SRC_DEMO_FILES src/main/cpp/demo.cpp)
set(SRC_TASK01_FILES src/main/cpp/task01.cpp)
set(SRC_TASK02_FILES src/main/cpp/task02.cpp)
set(SRC_TASK03_FILES src/main/cpp/task03.cpp)
set(SRC_TEST_FILES src/test/cpp/unit_tests.cpp)

# Setup Google Test
set(GOOGLE_TEST_ARCHIVE "release-1.11.0")
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/${GOOGLE_TEST_ARCHIVE}.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(main ${SRC_MAIN_FILES})
add_executable(demo ${SRC_DEMO_FILES})
add_executable(task01 ${SRC_TASK01_FILES})
add_executable(task02 ${SRC_TASK02_FILES})
add_executable(task03 ${SRC_TASK03_FILES})
add_executable(google-tests ${SRC_TEST_FILES})

# Now simply link against gtest or gtest_main as needed.
target_link_libraries(google-tests gtest_main)
include(GoogleTest)
gtest_discover_tests(google-tests)

target_include_directories(main PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src/main/cpp)
target_include_directories(demo PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src/main/cpp)
target_include_directories(task01 PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src/main/cpp)
target_include_directories(task02 PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src/main/cpp)
target_include_directories(task03 PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src/main/cpp)
target_include_directories(google-tests PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src/main/cpp)

# add custom commands that copy data input files to target working directories
add_custom_command(TARGET main PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/src/main/resources/main_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET demo PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/src/main/resources/demo_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET task01 PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/src/main/resources/task01_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET task02 PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/src/main/resources/task02_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET task03 PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/src/main/resources/task03_data.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET google-tests PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/src/test/resources/test_data.txt ${CMAKE_CURRENT_BINARY_DIR})
