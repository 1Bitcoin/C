all: app.exe test.exe

app.exe: main.o proc.o lib.o IO.o
	gcc -o app.exe proc.o lib.o main.o IO.o

test.exe: test.o proc.o IO.o lib.o
	gcc -o test.exe proc.o test.o IO.o lib.o

test.o: test.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c test.c 

main.o: main.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c main.c

lib.o: lib.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c lib.c

proc.o: proc.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c proc.c

IO.o: IO.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c IO.c

clean:
	rm -rf *o app.exe
