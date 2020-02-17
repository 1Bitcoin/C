all: app.exe test.exe

test.exe: main.o function.o test.o
	gcc -o test.exe function.o main.o test.o

app.exe: main.o function.o
	gcc -o app.exe function.o main.o

main.o: main.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c main.c


function.o: function.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c function.c

test.o: test.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c test.c

clean:
	rm -rf *o app.exe
