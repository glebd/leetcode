# this is the build file for project 
# it is autogenerated by the xmake build system.
# do not edit by hand.

# project
cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0091 NEW)
project(0206_reverse_linked_list LANGUAGES CXX C)

# target
add_executable(0206_reverse_linked_list "")
set_target_properties(0206_reverse_linked_list PROPERTIES OUTPUT_NAME "0206_reverse_linked_list")
set_target_properties(0206_reverse_linked_list PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/macosx/x86_64/release")
target_include_directories(0206_reverse_linked_list PRIVATE
    /Users/glebd/.xmake/packages/g/gtest/1.12.1/29c22d8bb07f415a8108eaa78056a17d/include
)
target_compile_options(0206_reverse_linked_list PRIVATE
    $<$<COMPILE_LANGUAGE:C>:-target>
    $<$<COMPILE_LANGUAGE:CXX>:-target>
    $<$<COMPILE_LANGUAGE:C>:x86_64-apple-macos13.1>
    $<$<COMPILE_LANGUAGE:CXX>:x86_64-apple-macos13.1>
    $<$<COMPILE_LANGUAGE:C>:-isysroot>
    $<$<COMPILE_LANGUAGE:CXX>:-isysroot>
    $<$<COMPILE_LANGUAGE:C>:/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.1.sdk>
    $<$<COMPILE_LANGUAGE:CXX>:/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.1.sdk>
    $<$<COMPILE_LANGUAGE:C>:-DNDEBUG>
    $<$<COMPILE_LANGUAGE:CXX>:-DNDEBUG>
)
set_target_properties(0206_reverse_linked_list PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(0206_reverse_linked_list PRIVATE c_std_11)
set_target_properties(0206_reverse_linked_list PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(0206_reverse_linked_list PRIVATE cxx_std_17)
if(MSVC)
    target_compile_options(0206_reverse_linked_list PRIVATE $<$<CONFIG:Debug>:-Od>)
else()
    target_compile_options(0206_reverse_linked_list PRIVATE -O0)
endif()
if(MSVC)
else()
    target_compile_options(0206_reverse_linked_list PRIVATE -fvisibility=hidden)
endif()
if(MSVC)
    set_property(TARGET 0206_reverse_linked_list PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
target_link_libraries(0206_reverse_linked_list PRIVATE
    gtest_main
    gtest
    gmock
    z
)
target_link_directories(0206_reverse_linked_list PRIVATE
    /Users/glebd/.xmake/packages/g/gtest/1.12.1/29c22d8bb07f415a8108eaa78056a17d/lib
)
target_link_options(0206_reverse_linked_list PRIVATE
    -target
    x86_64-apple-macos13.1
    -isysroot
    /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.1.sdk
    -stdlib=libc++
)
target_sources(0206_reverse_linked_list PRIVATE
    src/main.cpp
)

