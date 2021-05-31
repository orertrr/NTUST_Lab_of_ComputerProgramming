#include <stdio.h>
#include <math.h>

int main()
{
    double a, ans = 0;

    for (a = 1.0; a < 1000; a++)
    {
        ans += 1/(sqrt(a) + sqrt(a+1));
    }

    printf("%f\n", ans);
}