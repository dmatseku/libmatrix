cmake_minimum_required(VERSION 3.10.2)
project(matrix C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Ofast")

include_directories(includes)

add_library(matrix STATIC
        matrix/mat4/mat4_init.c matrix/mat4/mat4_add.c          matrix/mat4/mat4_add_scalar.c
        matrix/mat4/mat4_mult.c matrix/mat4/mat4_mult_scalar.c  matrix/mat4/mat4_print.c
        matrix/mat4/mat4_sub.c  matrix/mat4/mat4_sub_scalar.c   matrix/mat4/mat4_init_null.c

        vector/vec4/vec4_add.c          vector/vec4/vec4_add_scalar.c   vector/vec4/vec4_div_scalar.c
        vector/vec4/vec4_mult_scalar.c  vector/vec4/vec4_normal.c       vector/vec4/vec4_rev.c
        vector/vec4/vec4_scalar_mult.c  vector/vec4/vec4_sub.c          vector/vec4/vec4_sub_scalar.c

        vector/vec3/vec3_add.c          vector/vec3/vec3_add_scalar.c   vector/vec3/vec3_div_scalar.c
        vector/vec3/vec3_mult_scalar.c  vector/vec3/vec3_normal.c       vector/vec3/vec3_rev.c
        vector/vec3/vec3_scalar_mult.c  vector/vec3/vec3_sub.c          vector/vec3/vec3_sub_scalar.c
        vector/vec3/vec3_vector_mult.c

        vector/vec2/vec2_add.c          vector/vec2/vec2_add_scalar.c   vector/vec2/vec2_div_scalar.c
        vector/vec2/vec2_mult_scalar.c  vector/vec2/vec2_normal.c       vector/vec2/vec2_rev.c
        vector/vec2/vec2_scalar_mult.c  vector/vec2/vec2_sub.c          vector/vec2/vec2_sub_scalar.c

        quaternion/quaternion.h
        quaternion/quaternion_conjugate.c
        quaternion/quaternion_norm.c
        quaternion/quaternion_norm_nosqrt.c
        quaternion/quaternion_reverse.c

        operations/matrix_vector/mat_vec_4_mult.c

        operations/matrix/mat4_camera.c         operations/matrix/mat4_orthographic.c
        operations/matrix/mat4_perspective.c    operations/matrix/mat4_rotate.c
        operations/matrix/mat4_scale.c          operations/matrix/mat4_translate.c
        operations/matrix/mat4_yawpitchroll.c)