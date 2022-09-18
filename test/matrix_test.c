#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "matrix.h"
#include "ctest.h"

void t_setup(){
}

void t_teardown(){
}

void v3_init_vectors(){

        Vec3 v1;
        Vec3 v2;

        init_v3(&v1, 0);
        init_v3(&v2, 1);

	t_assert(v1[0] == 0);
	t_assert(v1[1] == 0);
	t_assert(v1[2] == 0);

	t_assert(v2[0] == 1);
	t_assert(v2[1] == 1);
	t_assert(v2[2] == 1);
}

void v4_init_vectors(){

        Vec4 v;

        init_v4(&v, 2);

	t_assert(v[0] == 2);
	t_assert(v[1] == 2);
	t_assert(v[2] == 2);
	t_assert(v[3] == 2);
}

void v3_add_vectors(){

        Vec3 v1 = { 1, 2, 3 };
        Vec3 v2 = { 4, 5, 6 };
        Vec3 r;

        add_v3(&r, &v1, &v2);

	t_assert(r[0] == 5);
	t_assert(r[1] == 7);
	t_assert(r[2] == 9);
}

int main(int argc, char** argv){

	t_init();
	t_test(v3_init_vectors);
	t_test(v4_init_vectors);
	t_test(v3_add_vectors);

	return t_done();
}

