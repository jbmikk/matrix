#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "matrix.h"
#include "ctest.h"

void t_setup(){
}

void t_teardown(){
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
	t_test(v3_add_vectors);

	return t_done();
}

