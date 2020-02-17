#ifndef UI_INPUT_H
#define UI_INPUT_H

typedef struct input_data
{
    uiEntry *size_array;
    uiEntry *array;
    uiEntry *position;
} input_data;

uiControl *input_info(void);
uiMultilineEntry *mul_entry;

#endif
