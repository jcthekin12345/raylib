#include <stdio.h>
#include <stdlib.h>

int main()
{
    char food[5];
    fgets(food, sizeof(food), stdin);
    printf("%s", food);
    return 0;
}
