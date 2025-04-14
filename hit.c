#include "hit.h";

void hit_set_face_normal(
    HitRecord *hit_record,
    Ray *ray,
    const Vec3 outward_normal
){

    if(dot(ray->direction, hit_record->normal) < 0){
        hit_record->isFrontFace = 1;
    } else{
        hit_record->isFrontFace = 0;
    }

    if(hit_record->isFrontFace){
        hit_record->normal = outward_normal;
    } else{
        hit_record->normal = vec3_mul_vd(outward_normal,-1.0);
    }
};