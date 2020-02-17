#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "ui_input.h"
#include "error_message.h"
#include "proc.h"

static void button_answer(uiButton *b, void *data);
static void work_with_file(char *s_size_array, char *s_array, char *s_position);


uiControl *input_info(void)
{
    uiBox *vbox = uiNewVerticalBox();
    uiBoxSetPadded(vbox, 1);

    uiBox *hbox = uiNewHorizontalBox();
    uiBoxSetPadded(hbox, 1);
    uiBoxAppend(vbox, uiControl(hbox), 0);

    uiGroup *group = uiNewGroup("Input data");
    uiGroupSetMargined(group, 1);
    uiBoxAppend(vbox, uiControl(group), 1);

    uiForm *entryForm = uiNewForm();
    uiFormSetPadded(entryForm, 1);
    uiGroupSetChild(group, uiControl(entryForm));

    uiEntry *size_array = uiNewEntry();
    uiFormAppend(entryForm,
        "Input size of array",
        uiControl(size_array),
        0);

    uiEntry *array = uiNewEntry();
    uiFormAppend(entryForm,
        "Input array",
        uiControl(array),
        0);

    uiEntry *position = uiNewEntry();
    uiFormAppend(entryForm,
        "Input position to insert",
        uiControl(position),
        0);

    input_data *info = malloc(sizeof(input_data));
    info->size_array = size_array;
    info->array = array;
    info->position = position;

    uiBoxAppend(vbox,
        uiControl(uiNewHorizontalSeparator()),
        0);

    uiButton *button = uiNewButton("Get answer!");
    uiBoxAppend(vbox,
        uiControl(button),
        0);

    mul_entry = uiNewMultilineEntry();
    uiMultilineEntrySetReadOnly(mul_entry, 1);
    uiBoxAppend(vbox, uiControl(mul_entry), 0);

    uiButtonOnClicked(button, button_answer, (void *)(info));

    return uiControl(vbox);
}

static void button_answer(uiButton *b, void *data)
{
    input_data info = *((input_data *)data);

    uiEntry *size_array = uiEntry(info.size_array);
    uiEntry *array = uiEntry(info.array);
    uiEntry *position = uiEntry(info.position);

    char *s_size_array = malloc(sizeof(char) * 20);
    char *s_array = malloc(sizeof(char) * 200);
    char *s_position = malloc(sizeof(char) * 20);

    s_size_array = uiEntryText(size_array);
    s_array = uiEntryText(array);
    s_position = uiEntryText(position);

    work_with_file(s_size_array, s_array, s_position);
}

static void work_with_file(char *s_size_array, char *s_array, char *s_position)
{
    FILE *file_with_data = fopen("data.txt", "w");

    fprintf(file_with_data, "%s\n%s\n%s\n", s_size_array, s_array, s_position);

    fclose(file_with_data);

    file_with_data = fopen("data.txt", "r");

    proc(file_with_data);
    fclose(file_with_data);
}


