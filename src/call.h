#ifndef CALL_H
#define CALL_H

#define VEC_MAP(_, JOIN, ...) \
	_(Vec3 *, v3, __VA_ARGS__) JOIN\
	_(Vec4 *, v4, __VA_ARGS__)

#define COMMA ,

#define EXPAND(TEMPLATE, T, ...) _Generic((T), \
	VEC_MAP(TEMPLATE, COMMA, __VA_ARGS__) \
)

#define NAME_TEMPLATE(TYPE, PREFIX, NAME) TYPE: NAME##PREFIX

#define v_init(V, ...) EXPAND(NAME_TEMPLATE, V, init_)((V), __VA_ARGS__)

#define v_add(V, ...) EXPAND(NAME_TEMPLATE, V, add_)((V), __VA_ARGS__)

#define v_sub(V, ...) EXPAND(NAME_TEMPLATE, V, sub_)((V), __VA_ARGS__)

// TODO: why variadic macros work for this but not for print?
#define v_norm(V, ...) EXPAND(NAME_TEMPLATE, V, norm_)((V), __VA_ARGS__)

#define v_scalar(V, ...) EXPAND(NAME_TEMPLATE, V, scalar_)((V), __VA_ARGS__)

#define v_dot(V, ...) EXPAND(NAME_TEMPLATE, V, dot_)((V), __VA_ARGS__)

#define v_print(V) EXPAND(NAME_TEMPLATE, V, print_)((V))

#endif //CALL_H

