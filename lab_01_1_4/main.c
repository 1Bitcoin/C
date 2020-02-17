#include <stdio.h>
#include <stdlib.h>
int entrance(int apartment);
int flor(int apartment);

int main()
{
    int apartment;

    printf("Input apartment number: ");
    scanf("%d", &apartment);

    printf("The entrance is %d\nThe floor is %d", entrance(apartment), flor(apartment));

    return 0;
}

int entrance(int apartment)
{
    return (apartment - 1) / 36 + 1;
}

int flor(int apartment)
{
    return (apartment - 1) % 36 / 4 + 1;
}
