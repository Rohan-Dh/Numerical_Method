#include<stdio.h>

int main(){
    int n, i, j, k, count = 0;
    printf("Enter the total number of data points: ");
    scanf("%d", &n);

    float data[n][n + 1], delta[n - 1], x, sum = 0;
    printf("Enter the data points below.\n");
    for(i = 0; i<n; i++){
        printf("(x%d, y%d): ", i+1, i+1);
        scanf("%f%f", &data[i][0], &data[i][1]);
    }
}