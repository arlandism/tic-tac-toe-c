
EXECUTABLE=tic_tac_toe

all: main.o

main.o: game.o board.o minimax.o tokens.o
	gcc main.c game.o board.o minimax.o tokens.o -o $(EXECUTABLE)

game.o: game.c board.o tokens.o minimax.o
	gcc -c game.c board.o tokens.o minimax.o

board.o:
	gcc -c board.c

tokens.o:
	gcc -c tokens.c

minimax.o:
	gcc -c minimax.c

clean:
	rm $(EXECUTABLE) *.o *~
