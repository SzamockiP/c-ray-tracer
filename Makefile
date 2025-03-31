program: main.o color.o
	gcc -std=c99 main.o color.o -o program

main.o: main.c vec3.h point3.h color.h ray.h
	gcc -std=c99 -c main.c -o main.o

color.o: color.c color.h
	gcc -std=c99 -c color.c -o color.o

clean:
	rm -f *.o program