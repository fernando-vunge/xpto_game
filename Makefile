bin/Xptogame: bin/maingame.o
	gcc -o bin/Xptogame bin/maingame.o

bin/maingame.o: maingame.c headergame.h
	gcc -c maingame.c -o bin/maingame.o

clean:
	rm bin/*.o