CFLAGS = -Wall -Wextra -std=c11

tictac: main.o library.o
	gcc $(CFLAGS) main.o library.o -o tictac

main.o: main.c 
	gcc $(CFLAGS) -c main.c

library.o: library.c
	gcc $(CFLAGS) -c library.c

clean: 
	echo "removing everything, expect the source files"
	rm main.o library.o tictac.o