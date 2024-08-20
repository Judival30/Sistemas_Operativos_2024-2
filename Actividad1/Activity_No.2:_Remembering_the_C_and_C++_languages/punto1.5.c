#include <stdio.h>

int fibonacciRecurs(int n)
{
    int ans = 0;
    if (n < 2)
        ans = n;
    else
        ans = fibonacciRecurs(n - 1) + fibonacciRecurs(n - 2);
    return ans;
}

int fibonacciIter(int n)
{
    int ini = 0, sig = 1, ans = 0, i;
    for (i = 0; i <= n; i++)
    {
        if (i < 2)
            ans = i;
        else
        {
            int sec = ini + sig;
            ini = sig;
            sig = sec;
            ans = sig;
        }
    }
    return ans;
}
int main()
{
    int n;
    printf("Digite el numero\n");
    scanf("%d", &n);
    printf("%d\n%d\n", fibonacciRecurs(n), fibonacciIter(n));
    return 0;
}