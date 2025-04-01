#include <stdio.h>
#include "vec3.h"
#include "point3.h"
#include "color.h"
#include "ray.h"


int main(void) {
    // Image
    int image_width =           400;
    const double ASPECT_RATIO = 16.0 / 9.0;

    int image_height =          (int) image_width / ASPECT_RATIO;
    image_height =           (image_height < 1) ? 1 : image_height;

    // Camera
    double focal_length =       1.0;
    double viewport_height =    2.0;
    double viewport_width =     viewport_height 
                                * (double) image_width/image_height;

    Point3 camera_center =      (Point3){.e = {0,0,0}};
    
    // Viewport edges
    Vec3 viewport_u =           (Point3){.e = {viewport_width,0,0}};
    Vec3 viewport_v =           (Point3){.e = {0,-viewport_height,0}};
    
    // Horizontal and vertical delta vectors
    Vec3 pixel_dt_u =           vec3_div_vd(&viewport_u, image_width);
    Vec3 pixel_dt_v =           vec3_div_vd(&viewport_v, image_height);

    // Upper left pixel location
    Vec3 focal_length_vec =     (Vec3){.e = {0,0,focal_length}};
    Vec3 viewport_upper_left =  vec3_sub_vv(&camera_center, &focal_length_vec);

    Vec3 viewport_diag      =   vec3_add_vv(&viewport_u, &viewport_v);
    Vec3 half_viewport_diag =   vec3_div_vd(&viewport_diag,2.0);

    viewport_upper_left =       vec3_sub_vv(&viewport_upper_left,
                                            &half_viewport_diag);


    Vec3 pixel_delta_diag =     vec3_add_vv(&pixel_dt_u, &pixel_dt_v);
    Vec3 half_pixel_dt_diag =   vec3_div_vd(&pixel_delta_diag, 2.0);

    Point3 pixel00_location =   vec3_add_vv(&viewport_upper_left,
                                            &half_pixel_dt_diag);


    printf("P3\n%d %d\n255\n",image_width,image_height);

    for(int i = 0; i < image_height; i++){
        fprintf(stderr,"\33[2K\rScanlines remaining: %d", image_height-i);
        for(int j = 0; j < image_width; j++){
            Vec3 pixel_delta_uj =       vec3_mul_vd(&pixel_dt_u, j);
            Vec3 pixel_delta_vi =       vec3_mul_vd(&pixel_dt_v, i);

            Vec3 pixel_delta_diag_ij =  vec3_add_vv(&pixel_delta_uj,
                                                    &pixel_delta_vi);

            // fprintf(stderr, "%f %f %f\n",pixel_delta_diag_ij.e[0],pixel_delta_diag_ij.e[1],pixel_delta_diag_ij.e[2]);

            Point3 pixel_center =       vec3_add_vv(&pixel00_location,
                                                    &pixel_delta_diag_ij);

            Vec3 ray_direction =        vec3_sub_vv(&pixel_center,
                                                    &camera_center);
            
            Ray ray = {.origin=camera_center, .direction=ray_direction};                                       
            // fprintf(stderr, "%f %f %f",ray.direction.e[0], ray.direction.e[1], ray.direction.e[2]);
            Color pixel_color = ray_color(&ray);        

            write_color(stdout, &pixel_color);
        }
    }
    fprintf(stderr,"\33[2K\rDone\n");

}