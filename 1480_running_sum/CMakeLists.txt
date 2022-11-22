cmake_minimum_required(VERSION 3.23)
project(1480_running_sum)

set(CMAKE_CXX_STANDARD 17)

add_executable(1480_running_sum main.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        # release-1.12.1
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
        # URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
target_link_libraries(1480_running_sum gtest_main gmock)
#add_test(NAME example_test COMMAND example)
