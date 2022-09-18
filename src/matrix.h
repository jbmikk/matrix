#ifndef CMATH_H
#define CMATH_H

//#define Vec(N) float Vec##N[N]
//#define Mat(N, M) float Mat##N##x##M[N][M]

typedef float Vec3[3];
typedef float Vec4[4];

typedef float Mat3[3][3];
typedef float Mat4[4][4];

void init_v3(Vec3 *r, float c);
float norm_v3(Vec3 *v);
void add_v3(Vec3 *r, Vec3 *v1, Vec3 *v2);
void sub_v3(Vec3 *r, Vec3 *v1, Vec3 *v2);
void scalar_v3(Vec3 *r, Vec3 *v, float s);
void cross_v3(Vec3 *r, Vec3 *u, Vec3 *v);

void init_v4(Vec4 *r, float c);
float dot_v4(Vec4 *v1, Vec4 *v2);
float dot_v4_c4(Vec4 *v, Mat4 *m, int col);
void mul_m4_v4(Vec4 *result, Mat4 *m, Vec4 *v);
void mul_m4(Mat4 *result, Mat4 *m1, Mat4 *m2);
void translate_m4(Mat4 *m, float x, float y, float z);
void scale_m4(Mat4 *m, float x, float y, float z);
void rotate_m4(Mat4 *m, float x, float y, float z, float angle);
void perspective_m4(Mat4 *m, float fovy, float aspect, float near, float far);
void look_at_m4(Mat4 *m, Vec3 *pos, Vec3 *center, Vec3 *up);

void print_v3(Vec3 *v);
void print_v4(Vec4 *v);
void print_m4(Mat4 *m);

#define Mat(A, B)
#endif //CMATH_H
