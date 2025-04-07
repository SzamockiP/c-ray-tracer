#include "ray.h"
#include "sphere.h"
#include "util.h"

Color ray_color(const Ray *ray) {

    double t = hit_sphere((Point3){.e={0,0,-1}},0.5,ray);
    if (t > 0.0) {
        Vec3 pt = ray_at(ray,t);
        Vec3 N = vec3_sub_vv(pt,(Point3){.e={0,0,-1}});
        N = vec3_unit_vector(N);
        return (Color){
            .e = {
                (N.e[0] + 1) * 0.5,
                (N.e[1] + 1) * 0.5,
                (N.e[2] + 1) * 0.5
            }
        };
    }

    Vec3 unit_direction = vec3_unit_vector(ray->direction);

    double a = 0.5 * (vec3_y(unit_direction) + 1);

    Color unit_color = {
        .e = {1.0, 1.0, 1.0}
    };

    Color tint_color = {
        .e = {0.5, 0.7, 1.0}
    };

    return lerp_vvd(unit_color, tint_color, a);
}