#include "sphere.h"
#include "point3.h"
#include "vec3.h"
#include <stdbool.h>

double sphere_hit(const Point3 center, double radius, const Ray *ray){
    Vec3 oc     = vec3_sub_vv(center,ray->origin);
    double a    = vec3_lenght_squared(ray->direction);
    double h    = vec3_dot_vv(ray->direction,oc);
    double c    = vec3_lenght_squared(oc) - (radius * radius);
    double disc = (h*h) - (a*c);

    if (disc < 0){
        return -1.0;
    }
    else{
        return (h - sqrt(disc)) / a;
    }

}
