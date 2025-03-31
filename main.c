#include <stdio.h>
#include "vec3.h"
#include "color.h"
#include "ray.h"

#define WIDTH 256
#define HEIGHT 256

int main(void) {
    const int image_width = WIDTH;
    const int image_height = HEIGHT;

    printf("P3\n%d %d\n255\n",image_width,image_height);

    for(int i = 0; i < image_height; i++){
        fprintf(stderr,"\33[2K\rScanlines remaining: %d", image_height-i);
        for(int j = 0; j < image_width; j++){
            Color pixel_color = {
                .e = {
                    (double) i / (image_width-1),
                    0,
                    (double) j / (image_height-1)
                }
            };

            write_color(stdout, &pixel_color);
        }
    }
    fprintf(stderr,"\33[2K\rDone\n");

}