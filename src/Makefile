CC=gcc
FLAGS=-c -std=c11 -Wall -Werror -Wextra

all: build

build: house travel

rebuild: clean build

house: house.o
	$(CC) house.o -o ../bin/house

travel: travel.o
	$(CC) travel.o -lm -o ../bin/travel

house.o:
	$(CC) $(FLAGS) house.c

travel.o:
	$(CC) $(FLAGS) travel.c

clean:
	rm -rf *.o
	rm -rf ../bin/house
	rm -rf ../bin/travel