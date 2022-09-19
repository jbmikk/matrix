#ifndef CALL_H
#define CALL_H

#define v_init(V, C) \
        _Generic((V), \
        Vec3 *: init_v3, \
        Vec4 *: init_v4)((V), (C))

#define v_add(R, V1, V2) \
        _Generic((V1), \
        Vec3 *: add_v3, \
        Vec4 *: add_v4)((R), (V1), (V2))

#define v_sub(R, V1, V2) \
        _Generic((V1), \
        Vec3 *: sub_v3, \
        Vec4 *: sub_v4)((R), (V1), (V2))

#define v_norm(V) \
        _Generic((V), \
        Vec3 *: norm_v3, \
        Vec4 *: norm_v4)((V))

#define v_scalar(R, V1, S) \
        _Generic((V1), \
        Vec3 *: scalar_v3, \
        Vec4 *: scalar_v4)((R), (V1), (S))

#define v_dot(V1, V2) \
        _Generic((V1), \
        Vec3 *: dot_v3, \
        Vec4 *: dot_v4)((V1), (V2))

#endif //CALL_H

