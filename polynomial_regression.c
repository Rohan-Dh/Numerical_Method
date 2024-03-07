#include<stdio.h>
#include<math.h>


void solve_matrix();

int main(){
    int n, order, i, j, k, count = 0;
    printf("Enter the total no of data: ");
    scanf("%d", &n);

    printf("Enter the order of the data: ");
    scanf("%d", &order);

    float x[n], y[n], temp;
    printf("Enter the data below\n");
    for(int i = 0; i<n; i++){
        printf("A[%d][%d]: ", i+1, i+1);
        scanf("%f%f", &x[i], &y[i]);
    }

    // calculating powers of x
    float temp_x[n][2*order-1];
    for(int i = 0; i<n; i++){
        for(int j=0; j<2*order-1; j++){
            temp_x[i][j] = pow(x[i],j+2);
        }
    }

    // calculating products of power of x and data of y
    float temp_y[n][order];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < order ; j++){
            temp_y[i][j] = pow(x[i], j+1)*y[i];
        }
    }

    // stores the sum of obtained powers of x
    float helper_x[2*order+1];
    helper_x[0] = n;
    for(int i=1; i<2*order+1; i++){
        float sum = 0;
        for(int j = 0; j<n; j++){
            if(i == 1){
                sum += x[j];
            }else{
                sum += temp_x[j][i-2];
            }
        }
        helper_x[i] = sum;
    }

    float holder[order + 1], coefficient[order + 1], matrix_x[order + 1][order + 1], matrix_y[order+1];
    int counter;
    
    // order+1 matrix is obtained
    for(int j = 0; j<order+1; j++){
        counter = 0;
        for(int k = j; k<=2*order+1; k++){
            holder[k-j] = helper_x[k];
            counter++;
            if (counter==order+1){
                break;
            }
        }
        for (int k = 0; k < order+1; k++){
            matrix_x[j][k] = holder[k];
        }
    }

    // stores the sum obtained from the products of powers of x and data of y
    for (int i = 0; i < order + 1; i++){
        float sum = 0;
        for (int j = 0; j < n; j++){
            if (i == 0){
                sum += y[j];
            }
            else{
                sum += temp_y[j][i - 1];
            }
        }
        matrix_y[i] = sum;
    }

    // arranging the data in augmented form
    float Augmented_matrix[order+1][order+2];
    for(int i = 0; i<order+1; i++){
        for(int j = 0; j<order+2; j++){
            if(j == order+1){
                Augmented_matrix[i][j] = matrix_y[i];
            }else{
                Augmented_matrix[i][j] = matrix_x[i][j];
            }
        }
    }



    // solving the Augmented_matrix 
    n = order + 1;
    for (i = 0; i < n; i++)
    {
        if (Augmented_matrix[i][i] == 0)
        {
            for (j = i + 1; j < n; j++)
            {
                if (Augmented_matrix[j][i] != 0)
                {
                    for (k = 0; k < n + 1; k++)
                    {
                        float temp;
                        temp = Augmented_matrix[i][k];
                        Augmented_matrix[i][k] = Augmented_matrix[j][k];
                        Augmented_matrix[j][k] = temp;
                    }
                    break;
                }
                else
                {
                    count++;
                }
            }
        }
        if (Augmented_matrix[i][i] != 1)
        {
            j = i;
            temp = Augmented_matrix[i][i];
            while (j < n + 1)
            {
                Augmented_matrix[i][j] = Augmented_matrix[i][j] / temp;
                j++;
            }
        }

        for (j = i + 1; j < n; j++)
        {
            temp = Augmented_matrix[j][i];
            for (k = i; k < n + 1; k++)
            {
                Augmented_matrix[j][k] = Augmented_matrix[j][k] - (temp * Augmented_matrix[i][k]);
            }
        }
    }

    for (i = n - 1; i > 0; i--)
    {
        for (j = i - 1; j >= 0; j--)
        {
            temp = Augmented_matrix[j][i];
            for (k = i; k < n + 1; k++)
            {
                Augmented_matrix[j][k] -= temp * Augmented_matrix[i][k];
            }
        }
    }

    // Printing the augmented matrix
    printf("After solving the Augmented matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%.2f\t", Augmented_matrix[i][j]);
        }
        printf("\n");
    }

    // co-efficients of regression equation is obtained
    for(i = 0; i<order+1; i++){
        for(j = 0; j<order+2; j++){
            if(j == order+1){
                coefficient[i] = Augmented_matrix[i][j];
            }
        }
    }

    // polynomial equation
    printf("y = ");
    for (int i = 0; i <= order; i++){
        if (i < order){
            printf("%.2fx^%d + ", coefficient[i], i);
        }
        else{
            printf("%.2fx^%d", coefficient[i], i);
        }
    }
    printf("\n");
}