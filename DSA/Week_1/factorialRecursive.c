#include <stdio.h>

int factorial(int n) {
int fact = 1;
if(n != 0)
fact = n * factorial(n-1);
return fact;
}
int main(){

int n, i, result;
printf("n: ");
scanf("%d", &n);
result = factorial(n);
printf("Factorial of n is %d\n", result);
return 0;
}