#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include "point3.h"
#include <stdbool.h>

bool hit_sphere(const Point3 center, double radius, const Ray *ray);

#endif