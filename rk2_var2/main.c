#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NORMAL 2
#define ERROR_READ_FILE 5
#define OK 0

typedef struct
{
    char name[30];
    int mass;
    int food;
    float food_to_mass;
}Animal;

void writeStudentT(Animal *animals, int count);
void readStudentsT(Animal *animals, int *count, int *out);
void delete_very_fat_animals(Animal *animals, int *count);
int food_to_mass(Animal *animals, int i);

int main()
{
    int count = 0;
    int out = OK;

    Animal animals[10];

    readStudentsT(animals, &count, &out);
    if (!out)
    {
        delete_very_fat_animals(animals, &count);
        writeStudentT(animals, count);
    }

    return 0;
}


void writeStudentT(Animal *animals, int count)
{
    FILE *f = fopen("text.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(f, "%s %d %d %.1f\n", animals[i].name, animals[i].mass, animals[i].food, animals[i].food_to_mass);

    fclose(f);
}

void readStudentsT(Animal *animals, int *count, int *out)
{
    FILE *f = fopen("text.txt", "r");

    if (f)
    {
        while (!feof(f))
        {
            fscanf(f, "%s %d %d\n", animals[*count].name, &animals[*count].mass, &animals[*count].food);
            *count += 1;
        }
    }

    else
        *out = ERROR_READ_FILE;

    if (!count)
        *out = ERROR_READ_FILE;

    fclose(f);
}

int food_to_mass(Animal *animals, int i)
{
    animals[i].food_to_mass = (float)animals[i].food / (float)animals[i].mass;
    return animals[i].food / animals[i].mass * 100;
}

void delete_very_fat_animals(Animal *animals, int *count)
{
    for (int i = 0; i < *count; i++ )
    {
        int flag = 0;

        if (food_to_mass(animals, i) > NORMAL && !strcmp(animals[i].name, "KOALA"))
        {
            for (int j = i; j < *count - 1; j++)
            {
                animals[j] = animals[j + 1];
                flag = 1;
            }

            if (i == *count - 1)
                *count -= 1;
        }

        if (flag)
        {
            *count -= 1;
            i--;
        }
    }
}
