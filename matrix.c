
#include "matrix.h"

float dot_v4_v4(Vec4 *v1, Vec4 *v2)
{
        return
                *v1[0] * *v2[0] +
                *v1[1] * *v2[1] +
                *v1[2] * *v2[2] +
                *v1[3] * *v2[3];
}

void mul_m4_v4(Mat4 *m, Vec4 *v, Vec4 *result)
{
        *result[0] = dot_v4_v4(m[0], v);
        *result[1] = dot_v4_v4(m[1], v);
        *result[2] = dot_v4_v4(m[2], v);
        *result[3] = dot_v4_v4(m[3], v);
}

