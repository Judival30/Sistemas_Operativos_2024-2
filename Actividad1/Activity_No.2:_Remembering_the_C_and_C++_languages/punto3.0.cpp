#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{
    int i;
    bool ans = true;
    for (i = 2; i < n / 2 && ans == 1; i++)
    {
        if (n % i == 0)
            ans = false;
    }
    return ans;
}

int main()
{
    printf("Digite el numero\n");
    int n, num;
    scanf("%d", &n);
    bool ans = isPrime(n);
    if (ans)
        printf("True\n");
    else
        printf("False\n");

    vector<int> lst;
    printf("Ingrese el size de la lista de numeros\n");
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &num);
        lst.push_back(num);
    }
    for (int i = 0; i < lst.size(); i++)
    {
        if (isPrime(lst[i]))
            printf("%d ", lst[i]);
    }
    printf("\n");

    // sort(lst.begin(), lst.end());
    int l, r;
    printf("Ingrese el rango a consultar:\n");
    scanf("%d %d", &l, &r);

    for (int i = l; i < r; i++)
    {
        if (isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}