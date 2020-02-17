MYMAIN=main

gcc -c *.c

ECHO STAGE 1 COMPLETE

gcc -fdiagnostics-color=always -pipe -Wall -Winvalid-pch -Wextra -Wpedantic -std=c99 -g -Wno-unused-parameter -Wno-switch -D_UI_STATIC -MD -MQ -MF -c ${MYMAIN}.c -o ${MYMAIN}.obj

ECHO STAGE 2 COMPLETE

c++ -o ${MYMAIN}.exe *.o -Wl,--allow-shlib-undefined -static -static-libgcc -static-libstdc++ -Wl,--start-group libui.a -luser32 -lkernel32 -lgdi32 -lcomctl32 -luxtheme -lmsimg32 -lcomdlg32 -ld2d1 -ldwrite -lole32 -loleaut32 -loleacc -luuid -lwindowscodecs -luser32 -lkernel32 -lgdi32 -lcomctl32 -luxtheme -lmsimg32 -lcomdlg32 -ld2d1 -ldwrite -lole32 -loleaut32 -loleacc -luuid -lwindowscodecs -Wl,--end-group -mconsole

ECHO STAGE 3 COMPLETE