
#include <stdio.h>
#include <math.h>

#include "matrix.h"

void print_v4(Vec4 *v)
{
	printf("[%f, %f, %f, %f]\n", (*v)[0], (*v)[1], (*v)[2], (*v)[3]);
}

void print_m4(Mat4 *m)
{
	print_v4(&((*m)[0]));
	print_v4(&((*m)[1]));
	print_v4(&((*m)[2]));
	print_v4(&((*m)[3]));
}

float dot_v4_v4(Vec4 *v1, Vec4 *v2)
{
        return
                (*v1)[0] * (*v2)[0] +
                (*v1)[1] * (*v2)[1] +
                (*v1)[2] * (*v2)[2] +
                (*v1)[3] * (*v2)[3];
}

float dot_v4_c4(Vec4 *v, Mat4 *m, int col)
{
        return
                (*v)[0] * (*m)[0][col] +
                (*v)[1] * (*m)[1][col] +
                (*v)[2] * (*m)[2][col] +
                (*v)[3] * (*m)[3][col];
}

void mul_m4_v4(Vec4 *result, Mat4 *m, Vec4 *v)
{
        (*result)[0] = dot_v4_v4(m[0], v);
        (*result)[1] = dot_v4_v4(m[1], v);
        (*result)[2] = dot_v4_v4(m[2], v);
        (*result)[3] = dot_v4_v4(m[3], v);
}

void mul_m4(Mat4 *result, Mat4 *m1, Mat4 *m2)
{
        (*result)[0][0] = dot_v4_c4(&((*m1)[0]), m2, 0);
        (*result)[0][1] = dot_v4_c4(&((*m1)[0]), m2, 1);
        (*result)[0][2] = dot_v4_c4(&((*m1)[0]), m2, 2);
        (*result)[0][3] = dot_v4_c4(&((*m1)[0]), m2, 3);
        (*result)[1][0] = dot_v4_c4(&((*m1)[1]), m2, 0);
        (*result)[1][1] = dot_v4_c4(&((*m1)[1]), m2, 1);
        (*result)[1][2] = dot_v4_c4(&((*m1)[1]), m2, 2);
        (*result)[1][3] = dot_v4_c4(&((*m1)[1]), m2, 3);
        (*result)[2][0] = dot_v4_c4(&((*m1)[2]), m2, 0);
        (*result)[2][1] = dot_v4_c4(&((*m1)[2]), m2, 1);
        (*result)[2][2] = dot_v4_c4(&((*m1)[2]), m2, 2);
        (*result)[2][3] = dot_v4_c4(&((*m1)[2]), m2, 3);
        (*result)[3][0] = dot_v4_c4(&((*m1)[3]), m2, 0);
        (*result)[3][1] = dot_v4_c4(&((*m1)[3]), m2, 1);
        (*result)[3][2] = dot_v4_c4(&((*m1)[3]), m2, 2);
        (*result)[3][3] = dot_v4_c4(&((*m1)[3]), m2, 3);
}

void scale_m4(Mat4 *m, float x, float y, float z)
{
	(*m)[0][0] = x;
	(*m)[0][1] = 0.0f;
	(*m)[0][2] = 0.0f;
	(*m)[0][3] = 0.0f;
	(*m)[1][0] = 0.0f;
	(*m)[1][1] = y;
	(*m)[1][2] = 0.0f;
	(*m)[1][3] = 0.0f;
	(*m)[2][0] = 0.0f;
	(*m)[2][1] = 0.0f;
	(*m)[2][2] = z;
	(*m)[2][3] = 0.0f;
	(*m)[3][0] = 0.0f;
	(*m)[3][1] = 0.0f;
	(*m)[3][2] = 0.0f;
	(*m)[3][3] = 1.0f;
}

void rotate_m4(Mat4 *m, float x, float y, float z, float angle)
{
	float a_sin = sin(angle);
	float a_cos = cos(angle);
	float len = sqrt(x*x+y*y+z*z);
	float ux = x/len;
	float uy = y/len;
	float uz = z/len;

	float xy = ux*uy*(1-a_cos);
	float xz = ux*uz*(1-a_cos);
	float yz = uy*uz*(1-a_cos);

	(*m)[0][0] = a_cos + ux*ux*(1-a_cos);
	(*m)[0][1] = xy-uz*a_sin;
	(*m)[0][2] = xz+uy*a_sin;
	(*m)[0][3] = 0.0f;

	(*m)[1][0] = xy+z*a_sin;
	(*m)[1][1] = a_cos + uy*uy*(1-a_cos);
	(*m)[1][2] = yz-ux*a_sin;
	(*m)[1][3] = 0.0f;

	(*m)[2][0] = xz-uy*a_sin;
	(*m)[2][1] = yz+ux*a_sin;
	(*m)[2][2] = a_cos + uz*uz*(1-a_cos);
	(*m)[2][3] = 0.0f;

	(*m)[3][0] = 0.0f;
	(*m)[3][1] = 0.0f;
	(*m)[3][2] = 0.0f;
	(*m)[3][3] = 1.0f;
}
