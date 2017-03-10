game:*.c
	gcc -o game *.c -lSDL
clean:
	rm game
