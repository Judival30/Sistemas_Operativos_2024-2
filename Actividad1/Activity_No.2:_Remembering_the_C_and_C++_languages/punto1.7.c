#include <stdio.h>

char cad[1000];

int lower(int size)
{
    int flag = 0, i, ascci;
    for (i = 0; i < size && flag == 0; i++)
    {
        ascci = cad[i];
        if (ascci >= 97)
            flag = 1;
    }
    return flag;
}

int main()
{
    char tmp;
    int i = 0, size = 0;

    while ((tmp = getchar()) != '\n' && i < 1000)
    {
        cad[i++] = tmp;
    }
    // printf("%s", cad);
    int ans = lower(i);
    if (ans == 1)
        printf("The cad have lower case letters\n");
    else
        printf("The cad don't have lower case letters\n");

    return 0;
}
