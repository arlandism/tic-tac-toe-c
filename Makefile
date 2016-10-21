
EXECUTABLE=tic_tac_toe

all: main.o

main.o: main.c game.o
	gcc main.c game.o -o $(EXECUTABLE)

game.o:
	gcc -c game.c -o game.o

clean:
	rm $(EXECUTABLE)
