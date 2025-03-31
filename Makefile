program: main.o color.o
	gcc main.o color.o -o main

main.o: main.c vec3.h point3.h color.h
	gcc -c main.c -o main.o

color.o: color.c color.h
	gcc -c color.c -o color.o

clean:
	rm -f *.o