// TODO: Test performence of passing Vec3 by value and by reference.
//       Value one might be faster cause of cache misses pointers generate
//       due to dereferencing.

// UPDATE: There's no meaning difference, on -O2/O3 it's 10 cycles difference,
//         when multiplication or sqrt operation takes much more cycles.


#ifndef VEC3_H
#define VEC3_H

#include <math.h>

typedef struct Vec3 {
    double  e[3];
} Vec3;

// GETTERS

static inline double vec3_x(const Vec3 *v){
    return v->e[0];
}

static inline double vec3_y(const Vec3 *v){
    return v->e[1];
}

static inline double vec3_z(const Vec3 *v){
    return v->e[2];
}

// OPERATORS

static inline Vec3 vec3_mul_vd(const Vec3 *v, double t){
    return (Vec3){
        .e = {
            v->e[0] * t,
            v->e[1] * t,
            v->e[2] * t
        }
    };
}

static inline Vec3 vec3_div_vd(const Vec3 *v, double t){
    return (Vec3){
        .e = {
            v->e[0] / t,
            v->e[1] / t,
            v->e[2] / t 
        }
    };
}

static inline Vec3 vec3_add_vv(const Vec3 *v1, const Vec3 *v2){
    return (Vec3){
        .e = {
            v1->e[0] + v2->e[0],
            v1->e[1] + v2->e[1],
            v1->e[2] + v2->e[2]
        }
    };
}

static inline Vec3 vec3_sub_vv(const Vec3 *v1, const Vec3 *v2){
    return (Vec3){
        .e = {
            v1->e[0] - v2->e[0],
            v1->e[1] - v2->e[1],
            v1->e[2] - v2->e[2]
        }
    };
}

static inline Vec3 vec3_mul_vv(const Vec3 *v1, const Vec3 *v2){
    return (Vec3){
        .e = {
            v1->e[0] * v2->e[0],
            v1->e[1] * v2->e[1],
            v1->e[2] * v2->e[2]
        }
    };
}

static inline Vec3 vec3_div_vv(const Vec3 *v1, const Vec3 *v2){
    return (Vec3){
        .e = {
            v1->e[0] / v2->e[0],
            v1->e[1] / v2->e[1],
            v1->e[2] / v2->e[2]
        }
    };
}

static inline double vec3_dot_vv(const Vec3 *v1, const Vec3 *v2){
    return v1->e[0] * v2->e[0]
         + v1->e[1] * v2->e[1]
         + v1->e[2] * v2->e[2];
}

static inline Vec3 vec3_cross_vv(const Vec3 *v1, const Vec3 *v2){
    return (Vec3){
        .e = {
            v1->e[1] * v2->e[2] - v1->e[2] * v2->e[1],
            v1->e[0] * v2->e[2] - v1->e[2] * v2->e[0],
            v1->e[0] * v2->e[1] - v1->e[1] * v2->e[0]
        }
    };
}

// METHODS

static inline double vec3_lenght(const Vec3 *v){
    return sqrt(v->e[0] * v->e[0] + v->e[1] * v->e[1] + v->e[2] * v->e[2]);
}

static inline double vec3_lenght_squared(const Vec3 *v) {
    return v->e[0] * v->e[0] + v->e[1] * v->e[1] + v->e[2] * v->e[2];
}

static inline Vec3 vec3_unit_vector(const Vec3 *v){
    return vec3_div_vd(v,vec3_lenght(v));
}

#endif
