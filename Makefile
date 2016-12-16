
EXECUTABLE=tic_tac_toe

all: main.o

main.o: game.o minimax.o tokens.o
	gcc main.c game.o minimax.o tokens.o -o $(EXECUTABLE)

game.o: game.c tokens.o minimax.o
	gcc -c game.c tokens.o minimax.o

tokens.o:
	gcc -c tokens.c

minimax.o:
	gcc -c minimax.c

clean:
	rm $(EXECUTABLE) *.o *~
