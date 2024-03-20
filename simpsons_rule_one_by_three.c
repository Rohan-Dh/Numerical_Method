#include <stdio.h>
#include <math.h>
#define e 2.71828
#define f(x) pow(e, x)

int main()
{
    int interval, i = 1, mode = 0;
    float sum, l_lim, u_lim, h, result, x;

    printf("Enter the value subinterval: ");
    scanf("%d", &interval);

    float y[interval + 1];

    printf("Enter the upper and lower limit (U-L): ");
    scanf("%f%f", &u_lim, &l_lim);

    printf("x\ty\n");
    h = (u_lim - l_lim) / interval;
    x = l_lim;
    y[0] = f(l_lim);
    printf("%.2f\t%.2f\n", x, y[0]);

    while (x < u_lim)
    {
        y[i] = f(x + h);
        printf("%.2f\t%.2f\n", x + h, y[i]);
        x += h;
        i++;
    }
    sum = y[0] + y[interval];

    for (i = 1; i < interval; i++)
    {
        if (mode == 0)
        {
            sum += 4 * y[i];
            mode += 2;
        }
        else
        {
            sum += 2 * y[i];
            mode -= 2;
        }
    }

    result = (h / 3) * sum;
    printf("The area under the given point of the curve is %.2f", result);
}