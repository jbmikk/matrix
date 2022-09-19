#ifndef CALL_H
#define CALL_H

#define VEC_MAP(_, JOIN, ...) \
	_(Vec3 *, v3, __VA_ARGS__) JOIN\
	_(Vec4 *, v4, __VA_ARGS__)

#define COMMA ,

#define CALL_EXPANSION(TYPE, PREFIX, NAME) TYPE: NAME##PREFIX

#define v_init(V, C) \
        _Generic((V), VEC_MAP(CALL_EXPANSION, COMMA, init_)) \
        ((V), (C))

#define v_add(R, V1, V2) \
        _Generic((V1), VEC_MAP(CALL_EXPANSION, COMMA, add_)) \
        ((R), (V1), (V2))

#define v_sub(R, V1, V2) \
        _Generic((V1), VEC_MAP(CALL_EXPANSION, COMMA, sub_)) \
        ((R), (V1), (V2))

#define v_norm(V) \
        _Generic((V), VEC_MAP(CALL_EXPANSION, COMMA, norm_)) \
        ((V))

#define v_scalar(R, V1, S) \
        _Generic((V1), VEC_MAP(CALL_EXPANSION, COMMA, scalar_)) \
        ((R), (V1), (S))

#define v_dot(V1, V2) \
        _Generic((V1), VEC_MAP(CALL_EXPANSION, COMMA, dot_)) \
        ((V1), (V2))

#endif //CALL_H

