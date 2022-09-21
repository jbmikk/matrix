#ifndef CMATH_H
#define CMATH_H

#include "vector.h"

//#define Mat(N, M) float Mat##N##x##M[N][M]

typedef float Mat3[3][3];
typedef float Mat4[4][4];

float dot_v4_c4(Vec4 *v, Mat4 *m, int col);
void mul_m4_v4(Vec4 *result, Mat4 *m, Vec4 *v);
void mul_m4(Mat4 *result, Mat4 *m1, Mat4 *m2);
void translate_m4(Mat4 *m, float x, float y, float z);
void scale_m4(Mat4 *m, float x, float y, float z);
void rotate_m4(Mat4 *m, float x, float y, float z, float angle);
void perspective_m4(Mat4 *m, float fovy, float aspect, float near, float far);
void look_at_m4(Mat4 *m, Vec3 *pos, Vec3 *center, Vec3 *up);
void print_m4(Mat4 *m);

#define Mat(A, B)
#endif //CMATH_H
