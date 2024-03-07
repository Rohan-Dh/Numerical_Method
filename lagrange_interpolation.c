#include<stdio.h>
int main(){
    float x, y_total = 0, temp;
    int n, i, j;

    printf("Enter the number of co-ordinate: ");
    scanf("%d", &n);

    float x_co[n], y_co[n];

    for (i = 0; i < n; i++)
    {
        printf("(x[%d], y[%d]): ", i, i);
        scanf("%f%f", &x_co[i], &y_co[i]);
    }

    printf("Enter the point where you want to find the value of y: ");
    scanf("%f", &x);

    for(i=0; i<n; i++){
        temp = 1;
        
        for (j = 0; j<n; j++){

            if(i!=j){
                temp *= (x - x_co[j])/(x_co[i] - x_co[j]);
            }

        }
        y_total += temp*y_co[i];
    }

    printf("The value of y in the point %.2f is %.2f", x, y_total);
}