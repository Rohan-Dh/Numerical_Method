#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a data point (x, y)
typedef struct
{
    float x;
    float y;
} DataPoint;

float compute_derivative(DataPoint data_points[], int num_points, float x)
{
    float divided_difference[num_points][num_points];

    // Initialize divided differences with y values
    for (int i = 0; i < num_points; i++){
        divided_difference[i][0] = data_points[i].y;
    }

    // Computing divided differences
    for (int j = 1; j < num_points; j++){
        for (int i = 0; i < num_points - j; i++){
            divided_difference[i][j] = (divided_difference[i + 1][j - 1] - divided_difference[i][j - 1]) /
                                       (data_points[i + j].x - data_points[i].x);
        }
    }

    // Computing the derivative at x
    float result = 0;
    for (int i = 0; i < num_points; i++)
    {
        float term = divided_difference[i][i];
        for (int j = 0; j < i; j++)
        {
            term *= (x - data_points[j].x);
        }
        result += term;
    }

    return result;
}

int main()
{
    int num_points;
    printf("Enter the number of data points: ");
    scanf("%d", &num_points);

    DataPoint data_points[num_points];

    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < num_points; i++){
        printf("Point %d: ", i + 1);
        scanf("%f%f", &data_points[i].x, &data_points[i].y);
    }

    float x;
    printf("Enter the value of x at which to compute the derivative: ");
    scanf("%f", &x);

    // Compute the derivative at the given x value
    float derivative = compute_derivative(data_points, num_points, x);
    printf("The derivative at x = %.2lf is: %.2lf\n", x, derivative);

    return 0;
}
