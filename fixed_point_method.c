#include<stdio.h>
#include<math.h>

#define f(x) pow((2*x+5)/2, 0.3333333333) //define converging equation here
#define allowed_error 0.0001 //define allowed error here

// function to find the error
float find_error(float x1, float x2){
    if(x1 < x2){
        return x2 - x1;
    }
    return x1 - x2;
}

// main function starts
int main(){
    float x1, x2, x3, x4, error = 1;
    printf("Enter the value of x1 and x2 such that f(x1)<0 and f(x2)>0 from hit and trial method: ");
    scanf("%f%f", &x1, &x2);

    x3 = (x1+x2)/2;
    // fixed point iteration algoritm is defined inside this while loop
    while (error > allowed_error){
        x4 = f(x3);
        error = find_error(x3, x4);
        x3 = x4;
        printf("%f\n", error);
    }

    // printing the root of the equation 
    printf("The required root is %f", x4);
}