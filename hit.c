#include "hit.h";

void hit_record_set_face_normal(
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

int hit_hittable_list(
    const HittableList hittable_list,
    const Ray *ray,
    double ray_tmin,
    double ray_tmax,
    HitRecord* rec
){
    HitRecord temp_rec;
    int is_hit_anything = 0;
    double closest_so_far = ray_tmax;

    for (int i = 0; i<hittable_list.count; i++) {
        if(hit_hittable(
            hittable_list.hittables[i],
            ray,ray_tmin,
            closest_so_far,
            &temp_rec)
        ){
            is_hit_anything = 1;
            closest_so_far = temp_rec.t;

            rec->isFrontFace = temp_rec.isFrontFace;
            rec->t = temp_rec.t;
            rec->p = temp_rec.p;
            rec->normal= temp_rec.normal;
        }
    }

    return is_hit_anything;
}