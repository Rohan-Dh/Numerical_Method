#include<stdio.h>
#include<math.h>
#define e 2.718281828
#define f(x) pow(x, 2) - 3/* change function here */
#define allowed_error 0.0001 /* change 'allowed error' here */

/* Calculating actual error */
double calculate_actual_error(double a , double b){
    if(a>b){
        printf("\terror = %.6f", a - b);
        return a - b;
    }else{
        printf("\terror = %.6f", b - a);
        return b - a;
    }
}

/* formatting table */
void calculate_table(double xp, double xn){
    double mid_value, actual_error = 1 /* (for inserting loop) */;

    /* attributes of table */
    printf("\ni\txp\t\txn\t\txr\t\tf(xr)");

    int a = 0; /* for iteration attribute */

    /* displaying data for each attributes */
    while (actual_error >= allowed_error)
    {
        mid_value = (xn+xp)/2;
        printf("\n%d\t%.6f\t%.6f\t%.6f\t%.6f",a+1, xp, xn, mid_value, f(mid_value));

        /* changing the value of xn and xp */
        if(f(mid_value)>0){
            xp = mid_value;
        }else{
            xn = mid_value;
        }
        actual_error = calculate_actual_error(xn, xp);
        a++;
    }
    printf("\nroot:- %.6f", mid_value);
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

    total_range = max - min + 1;
    double ranges_x[total_range], ranges_y[total_range];

    /* value of x for hit and trial method*/
    for(i = min; i<=max; i++){
        ranges_x[i-min] = i;
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
    int count = 0;
    for(i=0; i<total_range-1; i++){
        if(ranges_y[i]>0 && ranges_y[i+1]<0){
            count++;
            calculate_table(ranges_x[i], ranges_x[i+1]);
            printf("\n");
            
        }else if(ranges_y[i]<0 && ranges_y[i+1]>0){
            count++;
            calculate_table(ranges_x[i+1], ranges_x[i]);
            printf("\n");
        }
    }
    if(count == 0){
        printf("Sorry, couldn't find any root at a provided interval...");
    }
    return 0;
}