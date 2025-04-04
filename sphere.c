#include "sphere.h"
#include "point3.h"
#include "vec3.h"
#include <stdbool.h>

bool hit_sphere(const Point3 center, double radius, const Ray *ray){
    Vec3   oc =     vec3_sub_vv(center, ray->origin);
    double a =      vec3_dot_vv(ray->direction, ray->direction);
    double b =      -2.0 * vec3_dot_vv(ray->direction, oc);
    double c =      vec3_dot_vv(oc, oc) - (radius * radius);
    double desc =   (b * b) - (4 * a * c);  

    return (desc >= 0);
}
