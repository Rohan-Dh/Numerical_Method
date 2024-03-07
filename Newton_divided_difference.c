#include <stdio.h>

// Function to find the divided difference table
void dividedDifference(float x[], float y[][10], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }
}

// Function for finding the value of the polynomial
float applyFormula(float value, float x[], float y[][10], int n)
{
    float sum = y[0][0];

    for (int i = 1; i < n; i++)
    {
        float product = 1.0;
        for (int j = 0; j < i; j++)
        {
            product *= (value - x[j]);
        }
        sum += (y[0][i] * product);
    }
    return sum;
}

int main()
{
    float value, x[10], y[10][10], result;
    int i, j, n;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter data points:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i][0]);
    }

    // Function call to create divided difference table
    dividedDifference(x, y, n);

    printf("Enter value to interpolate: ");
    scanf("%f", &value);

    // Get the result
    result = applyFormula(value, x, y, n);

    printf("Interpolated value at %.2f is %.4f\n", value, result);

    return 0;
}
