cmake_minimum_required(VERSION 3.21)

include_directories("${CMAKE_SOURCE_DIR}/emsdk/upstream/emscripten/cache/sysroot/include")

project(hello)

file(GLOB_RECURSE SOURCES "src/*.c")

set(POST_JS_FILE "${CMAKE_SOURCE_DIR}/src/post.js")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --post-js ${POST_JS_FILE}")
add_executable(hello ${SOURCES})
target_link_options(hello PRIVATE
    "-sEXPORTED_RUNTIME_METHODS=[FS]"
    "-sWASM=1"
)

# target_link_libraries(hello PRIVATE m)
# set_target_properties(my_project PROPERTIES LINK_FLAGS "-s WASM=1")
if (CMAKE_SYSTEM_NAME STREQUAL Emscripten)
    set(CMAKE_EXECUTABLE_SUFFIX .js)
endif()
