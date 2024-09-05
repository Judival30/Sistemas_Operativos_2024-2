#include <stdio.h>

int main()
{
    int var1 = 100;
    float var2;

    var2 = var1;
    printf("Implicit Casting: = %d casted to = %.2f\n", var1, var2);
    var2 = 10.75;
    var1 = (int)var2;
    printf("Explicit Casting: = %d casted to = %.2f\n", var1, var2);

    return 0;
}
