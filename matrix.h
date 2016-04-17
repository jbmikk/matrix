#ifndef CMATH_H
#define CMATH_H

//#define Vec(N) float Vec##N[N]
//#define Mat(N, M) float Mat##N##x##M[N][M]

typedef float Vec4[4];
typedef float Mat4[4][4];

float dot_v4_v4(Vec4 *v1, Vec4 *v2);
void mul_m4_v4(Mat4 *m, Vec4 *v, Vec4 *result);

#define Mat(A, B)
#endif //CMATH_H
