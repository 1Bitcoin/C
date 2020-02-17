all: app.exe test.exe

app.exe: main.o lib.o IO_LIB.o
	gcc -o app.exe lib.o main.o IO_LIB.o

test.exe: test.o proc.o IO_TEST.o lib.o
	gcc -o test.exe proc.o test.o IO_TEST.o lib.o

test.o: test.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c test.c 

main.o: main.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c main.c

lib.o: lib.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c lib.c

proc.o: proc.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c proc.c

IO_TEST.o: IO_TEST.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c IO_TEST.c

IO_LIB.o: IO_LIB.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c IO_LIB.c

clean:
	rm -rf *o app.exe
