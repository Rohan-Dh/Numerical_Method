#include <stdio.h>

int main()
{
    int n, i, j, k;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    float original_mat[n][n], l[n][n], u[n][n];

    printf("Enter the data inside the matrix below\n");
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &original_mat[i][j]);
        }
    }

    printf("Your original matrix is \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%.2f\t", original_mat[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++){
        // Upper Triangular
        for (j = i; j < n; j++){
            float sum = 0;
            for (k = 0; k < i; k++){
                sum += (l[i][k] * u[k][j]);
            }
            u[i][j] = original_mat[i][j] - sum;
        }

        // Lower Triangular
        for (j = i; j < n; j++){
            if (i == j)
                l[i][i] = 1;
            else{
                float sum = 0;
                for (k = 0; k < i; k++){
                    sum += (l[j][k] * u[k][i]);
                }
                l[j][i] = (original_mat[j][i] - sum) / u[i][i];
            }
        }
    }

    printf("\nLower Triangular Matrix:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%.2f\t", l[i][j]);
        }
        printf("\n");
    }

    printf("\nUpper Triangular Matrix:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%.2f\t", u[i][j]);
        }
        printf("\n");
    }
    return 0;
}
