CC=gcc
FLAGS=-c -std=c11 -Wall -Werror -Wextra

all: build

build: house

rebuild: clean build

house: house.o
	$(CC) house.o -o ../bin/house

house.o:
	$(CC) $(FLAGS) house.c

clean:
	rm -rf *.o
	rm -rf ../bin/h*