
EXECUTABLE=tic_tac_toe

all: main.o

main.o: main.c game.o
	gcc main.c game.o -o $(EXECUTABLE)

game.o: 
	gcc -c game.c board.o tokens.o minimax.o -o game.o

board.o:
	gcc -c board.c -o board.o

tokens.o:
	gcc -c tokens.c -o tokens.o

minimax.o:
	gcc -c minimax.c -o minimax.o

clean:
	rm $(EXECUTABLE) game.o *~
