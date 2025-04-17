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

typedef enum HittableType {
    SPHERE
} HittableType;

typedef struct Hittable {
    const HittableType hittableType;
    int index;
} Hittable;

// TODO: make it vector
typedef struct HittableList{
    int count;
    Hittable *hittables;
} HittableList;

void hit_record_set_face_normal(
    HitRecord *hit_record,
    Ray *ray,
    const Vec3 outward_normal
);

int hit_hittable_list(
    const HittableList hittable_list,
    const Ray *ray,
    double ray_tmin,
    double ray_tmax,
    HitRecord *rec
);

int hit_hittable(Hittable hittable, const Ray *ray, double ray_tmin, double ray_tmax, HitRecord *rec);

#endif