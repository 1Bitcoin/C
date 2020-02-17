all: app.exe

app.exe: main.o func.o
	gcc -o app.exe func.o main.o
main.o: main.c
	gcc -Werror -Wall -g3 -pedantic -c main.c

func.o: func.c
	gcc -Werror -Wall -g3 -pedantic -c func.c

clean:
	rm -rf *o app.exe
