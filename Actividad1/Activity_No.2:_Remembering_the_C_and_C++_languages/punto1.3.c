#include <stdio.h>

int powerRecurs(int n, int pot, int acum)
{
    if (pot == 0)
        return acum;
    else
        powerRecurs(n, pot - 1, acum * n);
}
int powerIter(int n, int pot)
{
    int i, acum = 1;
    for (i = 0; i < pot; i++)
        acum *= n;
    return acum;
}

int main()
{
    int n, pot;
    printf("Digite el numero y su potencia\n");
    scanf("%d %d", &n, &pot);
    printf("%d\n%d\n", powerRecurs(n, pot, 1), powerIter(n, pot));
    return 0;
}