#include <stdio.h>

int factIter(int n){
    int ans = 1,i;
    for (i = 1; i <= n; i++)
        ans *= i;
    return ans;
}


int factRecur(int n, int acum){
    if (n == 1)
        return acum;
    else
        factRecur(n - 1, acum * n);
}

int main(){
    int n;
    printf("Digite el numero\n");
    scanf("%d", &n);
    printf("%d\n%d\n", factIter(n), factRecur(n, 1));
    
    return 0;
}