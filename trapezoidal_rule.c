#include<stdio.h>
#include<math.h>

float equation(float a){
    return 1/(1+pow(a, 2));
}

int main(){
    int interval, i;
    printf("Enter the interval you want to divide the curve: ");
    scanf("%d", &interval);

    float l_lim, u_lim, h, x, sum, a;
    printf("Enter the upper and lower limit of the function (upper_limit - lower_limit): ");
    scanf("%f%f", &u_lim, &l_lim);

    h = (u_lim - l_lim)/interval;
    x = l_lim;

    float y_co[interval+1];
    sum = equation(l_lim)+equation(u_lim);

    for (i = 1; i<interval; i++){
        sum += 2*equation(x+h);
        x += h;
    }

    printf("The area of the curve under the given equation is %.2f", (h/2)*sum);
}