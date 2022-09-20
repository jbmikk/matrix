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

void v3_dot_vectors(){

        Vec3 v1 = { 1, 0, 1 };
        Vec3 v2 = { 1, 1, 0 };

        float r = dot_v3(&v1, &v2);

        t_assert(r == 1);
}

void v4_dot_vectors(){

        Vec4 v1 = { 1, 0, 0, 1 };
        Vec4 v2 = { 1, 1, 1, 1 };

        float r = dot_v4(&v1, &v2);

        t_assert(r == 2);
}

void generic_v_init(){
        Vec3 v1;
        Vec4 v2;

        v_init(&v1, 2);
        v_init(&v2, 3);

        t_assert(v1[0] == 2);
        t_assert(v1[1] == 2);
        t_assert(v1[2] == 2);

        t_assert(v2[0] == 3);
        t_assert(v2[1] == 3);
        t_assert(v2[2] == 3);
        t_assert(v2[3] == 3);
}

void generic_v_dot(){
        Vec3 v1 = { 1, 0, 1 };
        Vec3 v2 = { 1, 1, 0 };

        Vec4 v3 = { 1, 0, 0, 1 };
        Vec4 v4 = { 1, 1, 1, 1 };

        float r1 = v_dot(&v1, &v2);
        float r2 = v_dot(&v3, &v4);

        t_assert(r1 == 1);
        t_assert(r2 == 2);
}

void generic_v_add(){

        Vec3 v1 = { 1, 2, 3 };
        Vec3 v2 = { 4, 5, 6 };
        Vec3 r1;

        Vec4 v3 = { 1, 2, 3, 4 };
        Vec4 v4 = { 4, 5, 6, 7 };
        Vec4 r2;

        v_print(&v1);
        v_print(&v4);
        v_add(&r1, &v1, &v2);
        v_add(&r2, &v3, &v4);

        t_assert(r1[0] == 5);
        t_assert(r1[1] == 7);
        t_assert(r1[2] == 9);

        t_assert(r2[0] == 5);
        t_assert(r2[1] == 7);
        t_assert(r2[2] == 9);
        t_assert(r2[3] == 11);
}

void generic_v_print(){

        Vec3 v1 = { 1, 2, 3 };
        Vec4 v2 = { 4, 5, 6, 7 };

        v_print(&v1);
        v_print(&v2);
}

int main(int argc, char** argv){

        t_init();
        t_test(v3_init_vectors);
        t_test(v4_init_vectors);
        t_test(v3_add_vectors);
        t_test(v3_dot_vectors);
        t_test(v4_dot_vectors);
        t_test(generic_v_init);
        t_test(generic_v_dot);
        t_test(generic_v_add);
        t_test(generic_v_print);

        return t_done();
}

