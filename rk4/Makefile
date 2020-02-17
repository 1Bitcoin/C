all: app_dynamic.exe

app_dynamic.exe: main.o libdynamic.dll
	gcc -o app_dynamic.exe main.o -L. -ldynamic -Wl,-rpath,.

main.o: main.c
	gcc -std=c99 -Werror -Wall -g3 -pedantic -c main.c

libdynamic.dll: read_info_from_bmp.o save_new_bmp.o work_with_convolution.o work_with_matrix.o work_with_struct.o
	gcc -shared -o libdynamic.dll read_info_from_bmp.o save_new_bmp.o work_with_convolution.o work_with_matrix.o work_with_struct.o

read_info_from_bmp.o: read_info_from_bmp.c
	gcc -c -fPIC read_info_from_bmp.c

save_new_bmp.o: save_new_bmp.c
	gcc -c -fPIC save_new_bmp.c

work_with_convolution.o: work_with_convolution.c
	gcc -c -fPIC work_with_convolution.c

work_with_matrix.o: work_with_matrix.c
	gcc -c -fPIC work_with_matrix.c

work_with_struct.o: work_with_struct.c
	gcc -c -fPIC work_with_struct.c
clean:
	rm -rf *.o app_dynamic.exe
