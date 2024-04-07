cmake_minimum_required(VERSION 3.27)

project(matrix C)

set(CMAKE_C_STANDARD 23)



set(GCC_GENERAL_COMPILER_FLAGS -Wall -Wextra -Werror -Wpedantic)

set(GCC_OPTIMIZATION_COMPILER_FLAGS -Ofast)

set(GCC_COMPILER_IS_OPTIMIZED CACHE BOOL OFF)



set(SOURCE_DIR ./source)

set(HEADERS_DIR includes)

set(VEC_DIR ${SOURCE_DIR}/vector)

set(MAT_DIR ${SOURCE_DIR}/matrix)

set(QUAT_DIR ${SOURCE_DIR}/quaternion)

set(CONVERT_DIR ${SOURCE_DIR}/conversion)

set(SOURCES
        ${VEC_DIR}/vec4.c
        ${VEC_DIR}/vec3.c
        ${VEC_DIR}/vec2.c
        ${MAT_DIR}/mat2.c
        ${MAT_DIR}/mat3.c
        ${MAT_DIR}/mat4.c
        ${QUAT_DIR}/quaternion.c
        ${VEC_DIR}/vec4d.c
        ${VEC_DIR}/vec3d.c
        ${VEC_DIR}/vec2d.c
        ${MAT_DIR}/mat2d.c
        ${MAT_DIR}/mat3d.c
        ${MAT_DIR}/mat4d.c
        ${QUAT_DIR}/quaterniond.c
        ${CONVERT_DIR}/to_matrix.c
        ${CONVERT_DIR}/to_quaternion.c
#        ${CONVERT_DIR}/to_vector.c
        ${CONVERT_DIR}/to_matrix_d.c
        ${CONVERT_DIR}/to_quaternion_d.c
#        ${CONVERT_DIR}/to_vector_d.c
)

add_library(matrix STATIC ${SOURCES})

target_include_directories(matrix PUBLIC ${HEADERS_DIR})

target_link_libraries(matrix m)

set_target_properties(matrix PROPERTIES PUBLIC_HEADER ${HEADERS_DIR}/libmatrix.h)

if(GCC_COMPILER_IS_OPTIMIZED)
    target_compile_options(matrix PRIVATE ${GCC_GENERAL_COMPILER_FLAGS} ${GCC_OPTIMIZATION_COMPILER_FLAGS})
    message(STATUS "Optimization is enabled")
else()
    target_compile_options(matrix PRIVATE ${GCC_GENERAL_COMPILER_FLAGS})
    message(STATUS "Optimization is disabled")
endif()