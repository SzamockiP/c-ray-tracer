#include "sphere.h"
#include "point3.h"
#include "vec3.h"
#include "ray.h"
#include "hit.h"
#include <stdbool.h>

// double sphere_hit(const Point3 center, double radius, const Ray *ray){
//     Vec3 oc     = vec3_sub_vv(center,ray->origin);
//     double a    = vec3_lenght_squared(ray->direction);
//     double h    = vec3_dot_vv(ray->direction,oc);
//     double c    = vec3_lenght_squared(oc) - (radius * radius);
//     double disc = (h*h) - (a*c);

//     if (disc < 0){
//         return -1.0;
//     }
//     else{
//         return (h - sqrt(disc)) / a;
//     }

// }

bool sphere_hit
(
    const Sphere *sphere,
    const Ray *ray, 
    double ray_tmin,
    double ray_tmax, 
    HitRecord* rec
){
    Vec3 oc     = vec3_sub_vv(sphere->center,ray->origin);
    double a    = vec3_lenght_squared(ray->direction);
    double h    = vec3_dot_vv(ray->direction,oc);
    double c    = vec3_lenght_squared(oc) - (sphere->radius * sphere->radius);

    double disc = (h*h) - (a*c);

    if (disc < 0)
        return false;

    double sqrtd = sqrt(disc);

    // Find the nearest root that lies in the acceptable range.
    double root = (h - sqrtd) / a;
    if (root <= ray_tmin || ray_tmax <= root) {
        root = (h + sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root)
            return false;
    }

    rec->t = root;
    rec->p = ray_at(ray,rec->t);
    rec->normal = vec3_sub_vv(rec->p,sphere->center);
    rec->normal = vec3_div_vd(rec->normal, sphere->radius);

    return true;
}