#include <stdio.h>
#include <math.h>
#define f(x) pow(x, 2) - 3   // change your equation here
#define allowed_error 0.0001 // change error allowed here

// function calculating error
float calc_error(float x1, float x2)
{
    if ((x2 - x1) < 0){
        return x1 - x2;
    }
    else
    {
        return x2 - x1;
    }
}

// secant algoritm to find error
float find_root(float x1, float x2)
{
    float x3, fx1, fx2;
    fx1 = f(x1);
    fx2 = f(x2);

    if (calc_error(x1, x2) < allowed_error)
    {
        x3 = x2;
        return x3;
    }
    else
    {
        x3 = x2 - ((x1 - x2) / (fx1 - fx2)) * fx2;

        x1 = x2;
        x2 = x3;

        return find_root(x1, x2);
    }
}

// main function starts here
int main()
{
    float x1, x2, x3;
    printf("Enter the two inital guesses obtained form hit and trail method: ");
    scanf("%f%f", &x1, &x2);

    x3 = find_root(x1, x2);
    printf("The root of given equation is %.5f", x3);

    return 0;
}