#include "ray.h"
#include "sphere.h"
#include "util.h"

Color ray_color(const Ray *ray) {
    if(hit_sphere(&(Point3){.e={0,0,-1}},0.5,ray))
        return (Color){.e = {1,0,0}};

    Vec3 unit_direction = vec3_unit_vector(&ray->direction);

    double a = 0.5 * (vec3_y(&unit_direction) + 1);

    Color unit_color = {
        .e = {1.0, 1.0, 1.0}
    };

    Color tint_color = {
        .e = {0.5, 0.7, 1.0}
    };

    return lerp_vvd(&unit_color, &tint_color, a);
}