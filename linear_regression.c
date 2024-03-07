#include<stdio.h>
#include<math.h>
#define f(x, m, c) m*x + c;

float find_mean(float x[], int total_data){
    float sum = 0;
    for(int i = 0; i<total_data; i++){
        sum += x[i];
    }
    return sum/total_data;
}

void find_regression(float x[], float y[], int total_data, float point){
    float x_mean = find_mean(x, total_data);
    float y_mean = find_mean(y, total_data);

    float sum1 = 0, slope, sum2 = 0, b;
    for(int i=0; i<total_data; i++){
        sum1 += (x[i]-x_mean)*(y[i]-y_mean);
        sum2 += pow((x[i]-x_mean), 2);
    }

    slope = sum1/sum2;
    b = y_mean - (slope*x_mean);
    
    float value = f(point, slope, b);

    printf("The value of y at the point %f is %f", point, value);
}

int main(){
    int n, i;
    printf("Enter the total number of data points: ");
    scanf("%d", &n);

    float X[n], Y[n];
    printf("Enter the data points below\n");
    for(i=0; i<n; i++){
        printf("(X[%d],y[%d]): ", i, i);
        scanf("%f%f", &X[i], &Y[i]);
    }

    float x;
    printf("Enter the regression point: ");
    scanf("%f", &x);

    char choice;
    printf("Make a choice (Enter 1 or 2 or q for quit)\n");
    printf("1) X on Y\n2) Y on X\n3) quit\n");
    scanf(" %c", &choice);

    
    switch(choice){
        case '1':
            find_regression(Y, X, n, x);
            break;
        case '2':
            find_regression(X, Y, n, x);
            break;
        case '3': 
            return(0);
        default: 
            printf("sorry invalid choice!!");
        return 0;
    }
}