cmake_minimum_required(VERSION 3.10.2)
project(matrix C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Ofast")

include_directories(includes)

set(HEADER vector_var.h libmatrix.h vector.h matrix.h structs.h  quaternion.h quaternion_var.h operations_matrix_vector.h operations_matrix.h)

add_library(matrix STATIC
        matrix/matrix_add.c			matrix/matrix_add_new.c 	matrix/matrix_addscalar.c
        matrix/matrix_cat.c 		matrix/matrix_cpy.c			matrix/matrix_create.c
        matrix/matrix_free.c		matrix/matrix_mult.c		matrix/matrix_multscalar.c
        matrix/matrix_print.c 		matrix/matrix_sub.c			matrix/matrix_sub_new.c
        matrix/matrix_subscalar.c	matrix/matrix_to_array.c

        vector/vector_add.c			vector/vector_add_new.c		vector/vector_addscalar.c
        vector/vector_cat.c			vector/vector_cpy.c			vector/vector_create.c
        vector/vector_divscalar.c	vector/vector_multscalar.c	vector/vector_normal.c
        vector/vector_rev.c			vector/vector_smult.c		vector/vector_sub.c
        vector/vector_sub_new.c		vector/vector_subscalar.c	vector/vector_vmult.c
        vector/vector_to_array.c

        vector/vector_variable/vector_var_create.c      vector/vector_variable/vector_var_add.c
        vector/vector_variable/vector_var_sub.c         vector/vector_variable/vector_var_addscalar.c
        vector/vector_variable/vector_var_subscalar.c   vector/vector_variable/vector_var_divscalar.c
        vector/vector_variable/vector_var_multscalar.c  vector/vector_variable/vector_var_normal.c
        vector/vector_variable/vector_var_rev.c         vector/vector_variable/vector_var_smult.c
        vector/vector_variable/vector_var_vmult.c

        quaternion/quat_conjugate.c		quaternion/quat_norm.c      quaternion/quat_conjugate_new.c
        quaternion/quat_norm_nosqrt.c	quaternion/quat_reverse.c   quaternion/quat_reverse_new.c

        quaternion/quaternion_variable/quat_var_conjugate.c quaternion/quaternion_variable/quat_var_reverse.c
        quaternion/quaternion_variable/quat_var_norm.c      quaternion/quaternion_variable/quat_var_norm_nosqrt.c

        operations/matrix_vector/mv_mult_var.c
        operations/matrix_vector/mv_mult.c
        operations/matrix_vector/mv_mult_new.c

        operations/matrix/m_rotate.c        operations/matrix/m_scale.c
        operations/matrix/m_translate.c     operations/matrix/m_yawpitchroll_new.c
        operations/matrix/m_orthographic.c  operations/matrix/m_perspective.c
        operations/matrix/m_camera.c        operations/matrix/m_yawpitchroll.c
        operations/matrix/m_rotate_new.c    operations/matrix/m_scale_new.c
        operations/matrix/m_translate_new.c)