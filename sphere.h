#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include "point3.h"
#include <stdbool.h>

typedef struct Sphere
{
    Point3 center;
    double radius;
} Sphere;


// double sphere_hit(const Point3 center, double radius, const Ray *ray);
bool sphere_hit
(
    const Sphere *sphere,
    const Ray *ray, 
    double ray_tmin,
    double ray_tmax, 
    HitRecord* rec
);

#endif