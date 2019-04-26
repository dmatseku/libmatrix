cmake_minimum_required(VERSION 3.10.2)
project(matrix C)

set(CMAKE_C_STANDARD 99)

include_directories(includes)

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

        quaternion/quat_conjugate.c		quaternion/quat_norm.c
        quaternion/quat_conjugate_new.c	quaternion/quat_norm_nosqrt.c	quaternion/quat_reverse.c

        operations/m_rotate.c		    operations/m_scale.c		operations/m_translate.c
        operations/mv_mult.c		    operations/mv_mult_new.c    operations/m_yawpitchroll_new.c
        operations/m_orthographic.c     operations/m_perspective.c  operations/m_camera.c
        operations/m_yawpitchroll.c)