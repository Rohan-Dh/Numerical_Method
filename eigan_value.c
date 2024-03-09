#include <stdio.h>
#include <conio.h>
#include <math.h>

float cal_abs(float x, float y){
    if(x<y){
        return y - x;
    }
    return x - y;
}

int main()
{
    int n, i, j, step = 1;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    float a[n][n], x[n], x_new[n];
    float temp, lambda_new, lambda_old, error, hold;

    printf("Enter Tolerable Error: ");
    scanf("%f", &error);

    /* input on matrix */

    printf("Enter Coefficient of Matrix:\n");
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){

            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);

        }
    }
    /* Reading Intial Guess Vector */
    printf("Enter Initial Guess Vector:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
    }

    /* Initializing Lambda_Old */
    lambda_old = 1;
/* Multiplication */
    do{
        for (i = 1; i <= n; i++)
        {
            temp = 0.0;
            for (j = 1; j <= n; j++)
            {
                temp = temp + a[i][j] * x[j];
            }
            x_new[i] = temp;
        }
        /* Replacing */
        for (i = 1; i <= n; i++)
        {
            x[i] = x_new[i];
        }
        /* Finding Largest */
        lambda_new = fabs(x[1]);
        for (i = 2; i <= n; i++)
        {
            if (fabs(x[i]) > lambda_new)
            {
                lambda_new = fabs(x[i]);
            }
        }
        /* Normalization */
        for (i = 1; i <= n; i++)
        {
            x[i] = x[i] / lambda_new;
        }
        /* Display */
        printf("\n\nSTEP-%d:\n", step);
        printf("Eigen Value = %f\n", lambda_new);
        printf("Eigen Vector:\n");
        for (i = 1; i <= n; i++)
        {
            printf("%f\t", x[i]);
        }
        /* Checking Accuracy */
        if (fabs(lambda_new - lambda_old) > error){
            hold = lambda_old;
            lambda_old = lambda_new;
            step++;
        }else{
            break;
        }
    } while (fabs(hold - lambda_new) > error);
}