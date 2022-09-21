#ifndef CVECTOR_H
#define CVECTOR_H

//#define Vec(N) float Vec##N[N]

typedef float Vec3[3];
typedef float Vec4[4];

void init_v3(Vec3 *r, float c);
void add_v3(Vec3 *r, Vec3 *v1, Vec3 *v2);
void sub_v3(Vec3 *r, Vec3 *v1, Vec3 *v2);
float norm_v3(Vec3 *v);
void scalar_v3(Vec3 *r, Vec3 *v, float s);
float dot_v3(Vec3 *v1, Vec3 *v2);
void cross_v3(Vec3 *r, Vec3 *u, Vec3 *v);
void print_v3(Vec3 *v);

void init_v4(Vec4 *r, float c);
void add_v4(Vec4 *r, Vec4 *v1, Vec4 *v2);
void sub_v4(Vec4 *r, Vec4 *v1, Vec4 *v2);
float norm_v4(Vec4 *v);
void scalar_v4(Vec4 *r, Vec4 *v, float s);
float dot_v4(Vec4 *v1, Vec4 *v2);
void print_v4(Vec4 *v);

#endif //CVECTOR_H
