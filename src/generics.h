
#define V3(_, JOIN) \
	_(0, 3) JOIN \
	_(1, 3) JOIN \
	_(2, 3) \

#define V4(_, JOIN) \
	_(0, 4) JOIN \
	_(1, 4) JOIN \
	_(2, 4) JOIN \
	_(3, 4) \

#define VEC(S) Vec##S
#define MAT(S) Mat##S

#define V_INIT_U(INDEX, LEN) (*r)[INDEX] = c;
#define V_INIT(S) void init_v##S(VEC(S) *r, float c) \
{ \
	V##S(V_INIT_U,) \
}

#define V_NORM_U(INDEX, LEN) (*v)[INDEX] * (*v)[INDEX]
#define V_NORM(S) float norm_v##S(VEC(S) *v) \
{ \
	return sqrt(V##S(V_NORM_U, +)); \
}

#define V_ADD_U(INDEX, LEN) (*r)[INDEX] = (*v1)[INDEX] + (*v2)[INDEX];
#define V_ADD(S) void add_v##S(VEC(S) *r, VEC(S) *v1, VEC(S) *v2) \
{ \
	V##S(V_ADD_U,) \
}

#define V_SUB_U(INDEX, LEN) (*r)[INDEX] = (*v1)[INDEX] - (*v2)[INDEX];
#define V_SUB(S) void sub_v##S(VEC(S) *r, VEC(S) *v1, VEC(S) *v2) \
{ \
	V##S(V_SUB_U,) \
}

#define V_SCALAR_U(INDEX, LEN) (*r)[INDEX] = s*(*v)[INDEX];
#define V_SCALAR(S) void scalar_v##S(VEC(S) *r, VEC(S) *v, float s) \
{ \
	V##S(V_SCALAR_U,) \
}

#define V_DOT_U(INDEX, LEN) (*v1)[INDEX] * (*v2)[INDEX]
#define V_DOT(S) float dot_v##S(VEC(S) *v1, VEC(S) *v2) \
{ \
        return V##S(V_DOT_U, +); \
}
