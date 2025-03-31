#include "color.h"

void write_color(FILE *out, const Color *pixel_color){
    const int r = (int)(255.999 * pixel_color->e[0]);
    const int g = (int)(255.999 * pixel_color->e[1]);
    const int b = (int)(255.999 * pixel_color->e[2]);

    fprintf(out, "%d %d %d\n",r,g,b);
}

