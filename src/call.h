#ifndef CALL_H
#define CALL_H

#define dot(V1, V2) \
        _Generic((V1), \
        Vec3 *: dot_v3, \
        Vec4 *: dot_v4)((V1), (V2))

#endif //CALL_H

