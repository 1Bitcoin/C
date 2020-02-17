all: app.exe test.exe


app.exe: main.o proc.o list.o choice.o factorization.o IO.o library_for_task.o
	gcc -o app.exe main.o proc.o list.o choice.o factorization.o IO.o library_for_task.o

test.exe: proc.o list.o choice.o factorization.o IO.o test.o library_for_task.o
	gcc -o test.exe proc.o list.o choice.o factorization.o IO.o test.o library_for_task.o

main.o: main.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c main.c

list.o: list.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c list.c

choice.o: choice.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c choice.c

factorization.o: factorization.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c factorization.c

library_for_task.o: library_for_task.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c library_for_task.c

IO.o: IO.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c IO.c

test.o: test.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c test.c

proc.o: proc.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c proc.c

clean: 
	rm -rf *o
