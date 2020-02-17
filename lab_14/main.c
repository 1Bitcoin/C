#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "ui_input.h"

static int onClosing(uiWindow *w, void *data);
static int onShouldQuit(void *data);

uiWindow *mainwin;


int main(void)
{
    uiInitOptions options;
    const char *err;
    uiTab *main_tab;

    memset(&options, 0, sizeof (uiInitOptions));
    err = uiInit(&options);
    if (err != NULL) 
    {
        fprintf(stderr, "error initializing libui: %s", err);
        uiFreeInitError(err);
        return 1;
    }

    mainwin = uiNewWindow("Pre alpha 0.99 lab 8 on GUI", 800, 200, 0);
    uiWindowOnClosing(mainwin, onClosing, NULL);
    uiOnShouldQuit(onShouldQuit, mainwin);

    main_tab = uiNewTab();
    uiWindowSetChild(mainwin, uiControl(main_tab));
    uiWindowSetMargined(mainwin, 1);

    uiTabAppend(main_tab, "Work with array", input_info());
    uiTabSetMargined(main_tab, 0, 1);

    uiControlShow(uiControl(mainwin));
    uiMain();

    return 0;
}

static int onClosing(uiWindow *w, void *data)
{
    uiQuit();
    return 1;
}

static int onShouldQuit(void *data)
{
    uiWindow *mainwin = uiWindow(data);
    uiControlDestroy(uiControl(mainwin));
    return 1;
}
