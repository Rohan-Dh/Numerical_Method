#include <stdio.h>

int find_facto(int a)
{
    if (a == 1)
    {
        return a;
    }
    return a * find_facto(a - 1);
}

int main()
{
    int n, i, j;
    printf("Enter total no of points: ");
    scanf("%d", &n);

    float x_co[n], y_co[n][n], delta[n - 1], s[n - 1], x;

    printf("Enter the co-ordinate details below.\n");
    for (i = 0; i < n; i++)
    {
        printf("(x[%d], y[%d]): ", i, i);
        scanf("%f%f", &x_co[i], &y_co[i][0]);
    }

    printf("Enter the point where you want to find the value of y: ");
    scanf("%f", &x);

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y_co[j][i] = y_co[j + 1][i - 1] - y_co[j][i - 1];
        }
    }

    s[0] = (x - x_co[n-1]) / (x_co[1] - x_co[0]);
    for (i = 1; i < n - 1; i++)
    {
        float s_total = 1;
        for (j = 0; j <= i; j++)
        {
            s_total *= (s[0] + j);
        }
        s[i] = s_total;
    }


    float y_total = y_co[n-1][0];
    for (i = 1; i < n; i++)
    {
        y_total += (y_co[n-i-1][i] * s[i - 1]) / find_facto(i);
    }

    printf("The value of y in the x co-ordinate %.2f is %.2f", x, y_total);
}