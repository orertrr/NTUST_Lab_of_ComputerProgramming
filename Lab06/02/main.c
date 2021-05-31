#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double *discriminant(int, int, int);

int main()
{
    int a, b, c;

    printf("There is a quadratic equation\n");
    printf("Please enter the coefficients of x:");
    scanf("%d %d %d", &a, &b, &c);

    double *roots = discriminant(a, b, c);

    if(roots == NULL)
        return 0;

    if(roots[0] != roots[1])
    {
        printf("The roots are:\n");
        printf("%f and %f\n", roots[0], roots[1]);
    }
    else if(roots[0] == roots[1])
    {
        printf("The root is:\n");
        printf("%f and %f\n", roots[0], roots[0]);
    }
}

//1 the equation has two real roots
//0 the equation has a double root
//-1 the equation has complex roots
double *discriminant(int a, int b, int c)
{
    int dis = b * b - 4 * a * c;

    double *roots = (double*)malloc(sizeof(double));

    if (dis > 0)
    {
        roots[0] = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
        roots[1] = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;

        return roots;
    }
    else if (dis == 0)
    {
        roots[0] = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
        roots[1] = roots[0];

        return roots;
    }
    else
    {
        printf("The roots are't real\n");
        return NULL;
    }
}