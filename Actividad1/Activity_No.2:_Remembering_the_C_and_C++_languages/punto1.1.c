#include <stdio.h>

int isLeap(int n){
    int ans = 0;
    if (n % 4 == 0)
        ans = 1;
    return ans;
}
int main(){
    int y;
    printf("Input the year\n");
    scanf("%d", &y);
    int ans = isLeap(y);
    if (ans == 1)
        printf("Is leap\n");
    else
        printf("Is not leap\n");
    return 0;
}