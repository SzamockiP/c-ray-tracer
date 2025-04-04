#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <stdio.h>

typedef Vec3 Color;

void write_color(FILE *out, const Color pixel_color);

#endif