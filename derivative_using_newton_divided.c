// #include<stdio.h>

// int main(){
//     int n, i, j, k, count = 0;
//     printf("Enter the total number of data points: ");
//     scanf("%d", &n);

//     float data[n][n + 1], delta[n - 1], x, sum = 0, product = 1;
//     printf("Enter the data points below.\n");
//     for(i = 0; i<n; i++){
//         printf("(x%d, y%d): ", i+1, i+1);
//         scanf("%f%f", &data[i][0], &data[i][1]);
//     }
//     // calculating didided difference table

//     for(i = 2; i < n+1; i++){
//         count = i - 1; 
//         for(j = 0; j < n - i + 1; j++){
//             data[j][i] = (data[j + 1][i - 1] - data[j][i - 1]) / (data[j+count][0] - data[j][0]);
//         }
//     }

//     for (i = 2; i < n + 1; i++){
//         delta[i-2] = data[0][i];
//     }

//     printf("Enter the point you want to find the derivative on: ");
//     scanf("%.2f", &x);

//     for(i = 0; i < n-1; i++){
//         count = i +1;
//         for(j = 0; j <= count; j++ ){
//             product 
//         }
//     }
// }