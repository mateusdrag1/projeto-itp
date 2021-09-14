FLAGS= -g -std=c99 -pedantic -Wall -Wextra -Werror 

all: start
start: obj/functions.o
		gcc main.c obj/functions.o -o programa $(FLAGS)
obj/functions.o: src/functions.c
		gcc src/functions.c -c $(FLAGS) -o obj/functions.o