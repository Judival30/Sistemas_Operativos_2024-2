#include <stdio.h>

void octal(int num)
{
    int arr[1000];
    int residuo, i = 0, j;
    while (residuo != 0)
    {
        residuo = num % 8;
        num = num / 8;
        arr[i++] = residuo;
    }
    printf("Numero en Octal: ");
    for (j = i - 2; j >= 0; j--)
        printf("%d", arr[j]);
    printf("\n");
}

void hexadecimal(int num)
{

    char arr[1000];
    int residuo;
    int i = 0;
    while (num != 0)
    {
        residuo = num % 16;
        num = num / 16;

        if (residuo >= 10)
        {
            arr[i++] = (residuo - 10) + 'A';
        }
        else
        {
            arr[i++] = residuo + '0';
        }
    }

    printf("Numero en Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", arr[j]);
    }
    printf("\n");
}

int main()
{

    int i;
    for (i = 1; i <= 10; i++)
    {
        printf("------------------------------\nNumero a transformar en decimal: %d\n", i);
        octal(i);
        hexadecimal(i);
    }

    return 0;
}