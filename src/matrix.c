
#include <stdio.h>
#include <math.h>

#include "matrix.h"

#define V3(_, JOIN) \
	_(0, x, 3) JOIN \
	_(1, y, 3) JOIN \
	_(2, z, 3) \

#define V4(_, JOIN) \
	_(0, x, 4) JOIN \
	_(1, y, 4) JOIN \
	_(2, z, 4) JOIN \
	_(4, w, 4) \

#define VEC(S) Vec##S
#define MAT(S) Mat##S

void print_v3(Vec3 *v)
{
	printf("[%f, %f, %f]\n", (*v).x, (*v).y, (*v).z);
}

void print_v4(Vec4 *v)
{
	printf("[%f, %f, %f, %f]\n", (*v).x, (*v).y, (*v).z, (*v).w);
}

#define V_PRINT_M(INDEX, KEY, LEN) print_v##LEN(&((*m).r[INDEX]));
void print_m4(Mat4 *m)
{
	V4(V_PRINT_M,);
}

#define V_NORM_U(INDEX, KEY, LEN) (*v).KEY * (*v).KEY
#define V_NORM(S) float norm_v##S(VEC(S) *v) \
{ \
	return sqrt(V3(V_NORM_U, +)); \
}

#define V_ADD_U(INDEX, KEY, LEN) (*r).KEY = (*v1).KEY + (*v2).KEY;
#define V_ADD(S) void add_v##S(VEC(S) *r, VEC(S) *v1, VEC(S) *v2) \
{ \
	V##S(V_ADD_U,) \
}

#define V_SUB_U(INDEX, KEY, LEN) (*r).KEY = (*v1).KEY - (*v2).KEY;
#define V_SUB(S) void sub_v##S(VEC(S) *r, VEC(S) *v1, VEC(S) *v2) \
{ \
	V##S(V_SUB_U,) \
}

#define V_SCALAR_U(INDEX, KEY, LEN) (*r).KEY = s*(*v).KEY;
#define V_SCALAR(S) void scalar_v##S(VEC(S) *r, VEC(S) *v, float s) \
{ \
	V##S(V_SCALAR_U,) \
}

#define V_DOT_U(INDEX, KEY, LEN) (*v1).KEY * (*v2).KEY;
#define V_DOT(S) float dot_v##S(VEC(S) *v1, VEC(S) *v2) \
{ \
        return V##S(V_DOT_U, +); \
}


V_ADD(3)
V_SUB(3)
V_NORM(3)
V_SCALAR(3)
V_DOT(3)

V_ADD(4)
V_SUB(4)
V_NORM(4)
V_SCALAR(4)
V_DOT(4)


float cross_v3(Vec3 *r, Vec3 *u, Vec3 *v)
{
	(*r).x = (*u).y * (*v).z -(*u).z * (*v).y;
	(*r).y = (*u).z * (*v).x -(*u).x * (*v).z;
	(*r).z = (*u).x * (*v).y -(*u).y * (*v).x;
}

#define V_DOT_COL(INDEX, KEY, LEN) (*v).KEY * (*m).r[INDEX][col]
float dot_v4_c4(Vec4 *v, Mat4 *m, int col)
{
        return V4(V_DOT_COL, +);
}

#define V_MUL_M(INDEX, KEY, LEN) (*r).KEY = dot_v##LEN((*m).r[INDEX], v);
void mul_m4_v4(Vec4 *r, Mat4 *m, Vec4 *v)
{
	V4(V_MUL_M,)
}

void mul_m4(Mat4 *result, Mat4 *m1, Mat4 *m2)
{
        (*result).r[0].x = dot_v4_c4(&((*m1).r[0]), m2, 0);
        (*result).r[0].y = dot_v4_c4(&((*m1).r[0]), m2, 1);
        (*result).r[0].z = dot_v4_c4(&((*m1).r[0]), m2, 2);
        (*result).r[0].w = dot_v4_c4(&((*m1).r[0]), m2, 3);
        (*result).r[1].x = dot_v4_c4(&((*m1).r[1]), m2, 0);
        (*result).r[1].y = dot_v4_c4(&((*m1).r[1]), m2, 1);
        (*result).r[1].z = dot_v4_c4(&((*m1).r[1]), m2, 2);
        (*result).r[1].w = dot_v4_c4(&((*m1).r[1]), m2, 3);
        (*result).r[2].x = dot_v4_c4(&((*m1).r[2]), m2, 0);
        (*result).r[2].y = dot_v4_c4(&((*m1).r[2]), m2, 1);
        (*result).r[2].z = dot_v4_c4(&((*m1).r[2]), m2, 2);
        (*result).r[2].w = dot_v4_c4(&((*m1).r[2]), m2, 3);
        (*result).r[3].x = dot_v4_c4(&((*m1).r[3]), m2, 0);
        (*result).r[3].y = dot_v4_c4(&((*m1).r[3]), m2, 1);
        (*result).r[3].z = dot_v4_c4(&((*m1).r[3]), m2, 2);
        (*result).r[3].w = dot_v4_c4(&((*m1).r[3]), m2, 3);
}

void translate_m4(Mat4 *m, float x, float y, float z)
{
	(*m).r[0].x = 1.0f;
	(*m).r[0].y = 0.0f;
	(*m).r[0].z = 0.0f;
	(*m).r[0].w = x;
	(*m).r[1].x = 0.0f;
	(*m).r[1].y = 1.0f;
	(*m).r[1].z = 0.0f;
	(*m).r[1].w = y;
	(*m).r[2].x = 0.0f;
	(*m).r[2].y = 0.0f;
	(*m).r[2].z = 1.0f;
	(*m).r[2].w = z;
	(*m).r[3].x = 0.0f;
	(*m).r[3].y = 0.0f;
	(*m).r[3].z = 0.0f;
	(*m).r[3].w = 1.0f;
}

void scale_m4(Mat4 *m, float x, float y, float z)
{
	(*m).r[0].x = x;
	(*m).r[0].y = 0.0f;
	(*m).r[0].z = 0.0f;
	(*m).r[0].w = 0.0f;
	(*m).r[1].x = 0.0f;
	(*m).r[1].y = y;
	(*m).r[1].z = 0.0f;
	(*m).r[1].w = 0.0f;
	(*m).r[2].x = 0.0f;
	(*m).r[2].y = 0.0f;
	(*m).r[2].z = z;
	(*m).r[2].w = 0.0f;
	(*m).r[3].x = 0.0f;
	(*m).r[3].y = 0.0f;
	(*m).r[3].z = 0.0f;
	(*m).r[3].w = 1.0f;
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

	(*m).r[0].x = a_cos + ux*ux*(1-a_cos);
	(*m).r[0].y = xy-uz*a_sin;
	(*m).r[0].z = xz+uy*a_sin;
	(*m).r[0].w = 0.0f;

	(*m).r[1].x = xy+z*a_sin;
	(*m).r[1].y = a_cos + uy*uy*(1-a_cos);
	(*m).r[1].z = yz-ux*a_sin;
	(*m).r[1].w = 0.0f;

	(*m).r[2].x = xz-uy*a_sin;
	(*m).r[2].y = yz+ux*a_sin;
	(*m).r[2].z = a_cos + uz*uz*(1-a_cos);
	(*m).r[2].w = 0.0f;

	(*m).r[3].x = 0.0f;
	(*m).r[3].y = 0.0f;
	(*m).r[3].z = 0.0f;
	(*m).r[3].w = 1.0f;
}

void perspective_m4(Mat4 *m, float fovy, float aspect, float near, float far)
{
	float f = cos(fovy/2.0f)/sin(fovy/2.0f);

	(*m).r[0].x = f/aspect;
	(*m).r[0].y = 0.0f;
	(*m).r[0].z = 0.0f;
	(*m).r[0].w = 0.0f;

	(*m).r[1].x = 0.0f;
	(*m).r[1].y = f;
	(*m).r[1].z = 0.0f;
	(*m).r[1].w = 0.0f;

	(*m).r[2].x = 0.0f;
	(*m).r[2].y = 0.0f;
	(*m).r[2].z = (far+near)/(near-far);
	(*m).r[2].w = (2*far*near)/(near-far);

	(*m).r[3].x = 0.0f;
	(*m).r[3].y = 0.0f;
	(*m).r[3].z = -1.0;
	(*m).r[3].w = 0.0f;
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

	M.r[0].x = S[0];
	M.r[0].y = S[1];
	M.r[0].z = S[2];
	M.r[0].w = 0;

	M.r[1].x = u[0];
	M.r[1].y = u[1];
	M.r[1].z = u[2];
	M.r[1].w = 0;

	M.r[2].x = -f[0];
	M.r[2].y = -f[1];
	M.r[2].z = -f[2];
	M.r[2].w = 0;

	M.r[3].x = 0.0f;
	M.r[3].y = 0.0f;
	M.r[3].z = 0.0f;
	M.r[3].w = 1.0f;

	translate_m4(&T, -(*pos).x, -(*pos).y, -(*pos).z);
	mul_m4(m, &M, &T);
}
