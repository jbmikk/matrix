
#include <stdio.h>
#include <math.h>

#include "matrix.h"
#include "generics.h"

#define V_PRINT_M(INDEX, LEN) print_v##LEN(&((*m)[INDEX]));
void print_m4(Mat4 *m)
{
	V4(V_PRINT_M,);
}

V_INIT(3)
V_ADD(3)
V_SUB(3)
V_NORM(3)
V_SCALAR(3)
V_DOT(3)
V_PRINT(3)

V_INIT(4)
V_ADD(4)
V_SUB(4)
V_NORM(4)
V_SCALAR(4)
V_DOT(4)
V_PRINT(4)


void cross_v3(Vec3 *r, Vec3 *u, Vec3 *v)
{
	(*r)[0] = (*u)[1] * (*v)[2] -(*u)[2] * (*v)[1];
	(*r)[1] = (*u)[2] * (*v)[0] -(*u)[0] * (*v)[2];
	(*r)[2] = (*u)[0] * (*v)[1] -(*u)[1] * (*v)[0];
}

#define V_DOT_COL(INDEX, LEN) (*v)[INDEX] * (*m)[INDEX][col]
float dot_v4_c4(Vec4 *v, Mat4 *m, int col)
{
        return V4(V_DOT_COL, +);
}

#define V_MUL_M(INDEX, LEN) (*r)[INDEX] = dot_v##LEN(m[INDEX], v);
void mul_m4_v4(Vec4 *r, Mat4 *m, Vec4 *v)
{
	V4(V_MUL_M,)
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

void translate_m4(Mat4 *m, float x, float y, float z)
{
	(*m)[0][0] = 1.0f;
	(*m)[0][1] = 0.0f;
	(*m)[0][2] = 0.0f;
	(*m)[0][3] = x;
	(*m)[1][0] = 0.0f;
	(*m)[1][1] = 1.0f;
	(*m)[1][2] = 0.0f;
	(*m)[1][3] = y;
	(*m)[2][0] = 0.0f;
	(*m)[2][1] = 0.0f;
	(*m)[2][2] = 1.0f;
	(*m)[2][3] = z;
	(*m)[3][0] = 0.0f;
	(*m)[3][1] = 0.0f;
	(*m)[3][2] = 0.0f;
	(*m)[3][3] = 1.0f;
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

void perspective_m4(Mat4 *m, float fovy, float aspect, float near, float far)
{
	float f = cos(fovy/2.0f)/sin(fovy/2.0f);

	(*m)[0][0] = f/aspect;
	(*m)[0][1] = 0.0f;
	(*m)[0][2] = 0.0f;
	(*m)[0][3] = 0.0f;

	(*m)[1][0] = 0.0f;
	(*m)[1][1] = f;
	(*m)[1][2] = 0.0f;
	(*m)[1][3] = 0.0f;

	(*m)[2][0] = 0.0f;
	(*m)[2][1] = 0.0f;
	(*m)[2][2] = (far+near)/(near-far);
	(*m)[2][3] = (2*far*near)/(near-far);

	(*m)[3][0] = 0.0f;
	(*m)[3][1] = 0.0f;
	(*m)[3][2] = -1.0;
	(*m)[3][3] = 0.0f;
}

void look_at_m4(Mat4 *m, Vec3 *pos, Vec3 *center, Vec3 *UP)
{
	Vec3 F, f, S, s, u, up;
	Mat4 M, T;

	sub_v3(&F, center, pos);

	scalar_v3(&f, &F, 1.0f/norm_v3(&F));
	scalar_v3(&up, UP, 1.0f/norm_v3(UP));
	
	cross_v3(&S, &f, &up);
	scalar_v3(&s, &S, 1.0f/norm_v3(&S));
	cross_v3(&u, &s, &f);

	M[0][0] = S[0];
	M[0][1] = S[1];
	M[0][2] = S[2];
	M[0][3] = 0;

	M[1][0] = u[0];
	M[1][1] = u[1];
	M[1][2] = u[2];
	M[1][3] = 0;

	M[2][0] = -f[0];
	M[2][1] = -f[1];
	M[2][2] = -f[2];
	M[2][3] = 0;

	M[3][0] = 0.0f;
	M[3][1] = 0.0f;
	M[3][2] = 0.0f;
	M[3][3] = 1.0f;

	translate_m4(&T, -(*pos)[0], -(*pos)[1], -(*pos)[2]);
	mul_m4(m, &M, &T);
}
