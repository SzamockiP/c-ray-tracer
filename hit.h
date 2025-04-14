#ifndef HIT_H
#define HIT_H

#include "ray.h"
#include "vec3.h"
#include "point3.h"


typedef struct HitRecord {
    Point3  p;
    Vec3    normal;
    double  t;
    int     isFrontFace;
} HitRecord;

typedef struct Hittable {
    typedef enum HittableType {
        SPHERE
    } HittableType;

    const HittableType hittableType;
    int index;
} Hittable;


void hit_set_face_normal(
    HitRecord *hit_record,
    Ray *ray,
    const Vec3 outward_normal
);

#endif