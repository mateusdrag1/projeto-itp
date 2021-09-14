FLAGS= -g -std=c99 -pedantic -Wall -Wextra -Werror

all: start
start: obj/main.o obj/file_manipulation.o obj/image.o obj/vector.o obj/terrain.o
		gcc obj/main.o obj/image.o obj/file_manipulation.o obj/vector.o obj/terrain.o -o terrain $(FLAGS)
obj/main.o: main.c
		gcc main.c -c $(FLAGS) -o obj/main.o
obj/file_manipulation.o: src/file_manipulation.c
		gcc src/file_manipulation.c -c $(FLAGS) -o obj/file_manipulation.o
obj/image.o: src/image.c
		gcc src/image.c -c $(FLAGS) -o obj/image.o
obj/vector.o: src/vector.c
		gcc src/vector.c -c $(FLAGS) -o obj/vector.o
obj/terrain.o: src/terrain.c
		gcc src/terrain.c -c $(FLAGS) -o obj/terrain.o

