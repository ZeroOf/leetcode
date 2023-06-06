cmake_policy(SET CMP0135 NEW)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

link_libraries(gtest_main gtest)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/leetcode/editor/en/*.cpp)
foreach (FILE IN LISTS SOURCES)
    get_filename_component(FILE_NO_EXT ${FILE} NAME_WE)

    if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${FILE_NO_EXT})
        FILE(MAKE_DIRECTORY ${FILE_NO_EXT})
        FILE(WRITE ${FILE_NO_EXT}/CMakeLists.txt
                "project(${FILE_NO_EXT})\n"
                "enable_testing()\n"
                "add_executable(\${PROJECT_NAME} test.cpp)\n"
                "include(GoogleTest)\n"
                "gtest_discover_tests(\${PROJECT_NAME})\n"
                )

        file(WRITE ${FILE_NO_EXT}/test.cpp
                "#include <gtest/gtest.h>\n"
                "#include <${FILE}>"
                )
    endif ()

    add_subdirectory(${FILE_NO_EXT})
endforeach ()

