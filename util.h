#ifndef UTIL_H
#define UTIL_H

#include "vec3.h"

static inline double lerp_ddd(double start, double end, double a){
    return start + a * (end - start);
}

static inline Vec3 lerp_vvd(const Vec3 start, const Vec3 end, double a){
    return (Vec3){
        .e = {
            lerp_ddd(start.e[0], end.e[0], a),
            lerp_ddd(start.e[1], end.e[1], a),
            lerp_ddd(start.e[2], end.e[2], a)
        }
    };
}

#endif