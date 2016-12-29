
EXECUTABLE=tic_tac_toe

all: main.o

main.o: game.o dumbai.o tokens.o
	gcc main.c game.o dumbai.o tokens.o -o $(EXECUTABLE)

game.o: game.c tokens.o dumbai.o
	gcc -c game.c tokens.o dumbai.o

tokens.o:
	gcc -c tokens.c

dumbai.o:
	gcc -c dumbai.c

clean:
	rm $(EXECUTABLE) *.o *~
