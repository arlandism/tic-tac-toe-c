
SOURCES=main.c
EXECUTABLE=tic_tac_toe

all: main.o

main.o: main.c
	gcc main.c -o $(EXECUTABLE)

clean:
	rm tic_tac_toe
