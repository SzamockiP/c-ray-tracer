CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -Werror

program: main.o color.o ray.o sphere.o
	gcc $(CFLAGS) main.o color.o ray.o sphere.o -o program -lm

main.o: main.c vec3.h point3.h color.h ray.h sphere.h util.h
	gcc $(CFLAGS) -c main.c -o main.o

color.o: color.c color.h
	gcc $(CFLAGS) -c color.c -o color.o

ray.o: ray.c ray.h util.h sphere.h
	gcc $(CFLAGS) -c ray.c -o ray.o

sphere.o: sphere.c sphere.h vec3.h point3.h
	gcc $(CFLAGS) -c sphere.c -o sphere.o

clean:
	rm -f *.o program *.ppm
