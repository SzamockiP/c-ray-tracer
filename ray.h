#ifndef RAY_H
#define RAY_H

#include "vec3.h"
#include "point3.h"
#include "color.h"

typedef struct Ray {
    Point3  origin;
    Vec3    direction;
} Ray;

inline Point3 ray_at(const Ray *ray, double t){
    return (Point3){
        .e = {
            (ray->origin.e[0] + ray->origin.e[0]) * t,
            (ray->origin.e[1] + ray->origin.e[1]) * t,
            (ray->origin.e[2] + ray->origin.e[2]) * t
        }
    };
}

Color ray_color(const Ray *ray);

#endif
