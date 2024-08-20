#include <stdio.h>

int isEven(int n)
{
    int ans = 0;
    if (n % 2 == 0)
        ans = 1;
    return ans;
}

int main()
{
    int n;
    printf("Digite el numero\n");
    scanf("%d", &n);
    int ans = isEven(n);
    if (ans == 1)
        printf("Is even\n");
    else
        printf("Is odd\n");
    return 0;
}