#include <stdio.h>

#define INF_INT 2147483647

int greaterNum(int arr[])
{
    int acum = -INF_INT, i;

    for (i = 0; i < 3; i++)
    {
        if (acum < arr[i])
            acum = arr[i];
    }
    return acum;
}

int main()
{
    int arr[3], i = 0, size = 3, a;
    printf("Digite los 3 numeros\n");
    while (size--)
        scanf("%d", &arr[i++]);
    printf("El numero mayor es: %d\n", greaterNum(arr));
    return 0;
}