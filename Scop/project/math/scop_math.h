#ifndef SCOP_MATH_H
# define SCOP_MATH_H


# include "libft_error.h"
# include "libft_standart.h"
# include <stdio.h>
# include <stdarg.h>
# include <math.h>


//						COMMON


typedef enum			e_axis
{
	axis_x,
	axis_y,
	axis_z
}						t_axis;

typedef enum			e_sign
{
	sign_plus = +1,
	sign_minus = -1
}						t_sign;


//						VECTOR


typedef struct 			s_vector2
{
	float				x;
	float				y;
}						t_vector2;

typedef struct 			s_vector3
{
	float				x;
	float				y;
	float				z;
}						t_vector3;

typedef struct 			s_vector4
{
	float				x;
	float				y;
	float				z;
	float				w;
}						t_vector4;

t_vector2				vector2_empty();
t_vector2				vector2_pack(float x, float y);
t_vector2				vector2_add(t_vector2 a, t_vector2 b);
t_vector2				vector2_sub(t_vector2 a, t_vector2 b);
t_vector2				vector2_mul(t_vector2 vector, float value);
t_vector2				vector2_div(t_vector2 vector, float value);
void 					vector2_print(t_vector2 vector);

t_vector3				vector3_empty();
t_vector3				vector3_pack(float x, float y, float z);
float 					*vector3_value(t_vector3 *vector, int index);
void 					vector3_print(t_vector3 vector);
t_vector3				vector3_add(t_vector3 a, t_vector3 b);
t_vector3				vector3_sub(t_vector3 a, t_vector3 b);
t_vector3				vector3_mul(t_vector3 vector, float value);
t_vector3				vector3_div(t_vector3 vector, float value);
float					vector3_dot(t_vector3 a, t_vector3 b);
t_vector3				vector3_cross(t_vector3 a, t_vector3 b);
float 					vector3_length_squared(t_vector3 vector);
float 					vector3_length(t_vector3 vector);
t_vector3				vector3_normalize(t_vector3 vector);
t_vector3				vector3_rotate(t_vector3 vector, t_axis axis, float angle);
t_vector3 				vector3_rotate_euler(t_vector3 vector, t_vector3 angle);
t_vector3 				vector3_min(t_vector3 a, t_vector3 b);
t_vector3 				vector3_max(t_vector3 a, t_vector3 b);

t_vector4				vector4_pack(float x, float y, float z, float w);
float 					*vector4_value(t_vector4 *vector, int index);
void 					vector4_print(const t_vector4 *vector);


//						MATRIX


typedef struct 			s_matrix
{
	float				data[4][4];
}						t_matrix;

t_matrix				matrix_empty();
t_matrix				matrix_identity();

t_matrix				matrix_product(t_matrix a, t_matrix b);
t_matrix				matrix_product_multiple(int number, ...);

t_matrix				matrix_translate(t_vector3 value);
t_matrix				matrix_scale(float value);

t_matrix				matrix_perspective(float fov, float aspect_ratio, float near, float far);
t_matrix				matrix_look_at(t_vector3 from, t_vector3 to, t_vector3 up);

t_matrix				matrix_rotation_x(float angle);
t_matrix				matrix_rotation_y(float angle);
t_matrix				matrix_rotation_z(float angle);
t_matrix				matrix_rotation(t_vector3 angle);
t_matrix				matrix_rotate_around_axis(t_vector3 axis, float angle);

void					matrix_print(const t_matrix *matrix);


//						OTHER


float 					degrees_to_radians(float value);

#endif
