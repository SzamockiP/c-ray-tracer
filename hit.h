#ifndef HIT_H
#define HIT_H

#include "ray.h"
#include "vec3.h"
#include "point3.h"

typedef struct hit_record {
    Point3  p;
    Vec3    normal;
    double  t;
} hit_record;


#endif