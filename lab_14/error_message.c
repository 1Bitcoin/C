#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "error_message.h"


void input_error()
{
    uiMsgBoxError(mainwin,
        "Error input!",
        "Check size array or array or valid position");
}

