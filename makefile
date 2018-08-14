
gameOfLife: defs.o zeroPlayer.o twoPlayer.o gameIO.o main.o
	gcc defs.o zeroPlayer.o twoPlayer.o gameIO.o main.o -o gameOfLife

defs.o: defs.h
	gcc -c defs.c

zeroPlayer.o: zeroPlayer.h defs.h
	gcc -c zeroPlayer.c

twoPlayer.o: twoPlayer.h defs.h
	gcc -c twoPlayer.c

gameIO.o: gameIO.h defs.h zeroPlayer.h twoPlayer.h
	gcc -c gameIO.c

main.o: main.c defs.h zeroPlayer.h twoPlayer.h gameIO.h
	gcc -c main.c

clean:
	rm -f *.o
