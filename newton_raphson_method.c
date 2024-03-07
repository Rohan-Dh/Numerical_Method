#include<stdio.h>
#include<math.h>
#define e 2.718281828
#define f(x) (x*pow(e, x))-cos(x)
#define g(x) (x*pow(e, x)) + pow(e, x) + sin(x)
#define allowed_error 0.0001 /* change 'allowed error' here */


double completing_table(double xi){
    int i = 0;
    double error = 1, x1;

    printf("\ni\txi\t\tx(i+1)\t\tf(x(i+1))");
    while (error>allowed_error)
    {
        double fxi = f(xi);
        double gxi = g(xi);
        x1 = xi - (fxi/gxi);
        if((x1 - xi)<0){
            error = xi - x1;
        }else{
            error = x1 - xi;
        }
        printf("\n%d\t%.6f\t%.6f\t%.6f", i+1, xi, x1, f(x1));
        printf("\t\terror = %.6f", error);
        xi = x1;
        i++;
    }
    printf("\nRoot:- %.6f", x1);
} 

int main(){
    int max, min, i, total_range;

    printf("Enter the range as the value of x for hit and trail method: ");
    scanf("%d%d", &min, &max);

    total_range = max - min + 1;
    if(total_range<=0){
        printf("Please provide range in correct format i.e. (small_no large_no)");
        return 1;
    }
    double ranges_x[total_range], ranges_y[total_range];

    /* value of x for hit and trial method*/
    for(i = min; i<=max; i++){
        ranges_x[i-min] = i + 0.599; /* if all roots aren't showing, just adjust numeric data here*/
    }

    /* value of y */
    for(i = 0; i<total_range; i++){
        ranges_y[i] = f(ranges_x[i]);
    }

    /* printing the value of values of x and values of y */
    printf("x\t");
    for(i = 0; i<total_range; i++){
        printf("%.1f\t",ranges_x[i]);
    }
    printf("\n");

    printf("y\t");
    for(i = 0; i<total_range; i++){
        printf("%.1f\t",ranges_y[i]);
    }
    printf("\n");

    /* Storing the value of xn and xp */
    int count = 0; /*counter if there exits no root in a given interval */
    int pre_x0, pre_x1, a;
    for(i = 0; i<total_range-1; i++){
        if((ranges_y[i]>0 && ranges_y[i+1]<0) || (ranges_y[i]<0 && ranges_y[i+1]>0)){
            completing_table(ranges_x[i+1]);
            printf("\n");
            count++;
        }else if(ranges_y[i] == 0){
            count ++;
            printf("f(%.0f) = 0\tso %.0f is the root\n", ranges_x[i], ranges_x[i]);
        }
    }
    if(count == 0){
        printf("Sorry, couldn't find any root at a provided interval...");
    }
    return 0;
}