program: main.o color.o ray.o
	gcc -std=c99 main.o color.o ray.o -o program -lm

main.o: main.c vec3.h point3.h color.h ray.h
	gcc -std=c99 -c main.c -o main.o

color.o: color.c color.h
	gcc -std=c99 -c color.c -o color.o

ray.o: ray.c ray.h util.h
	gcc -std=c99 -c ray.c -o ray.o

clean:
	rm -f *.o program