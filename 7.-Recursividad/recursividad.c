#include <stdio.h>

long int factorial(int n) {
   if(n >= 1)
       return n * factorial(n-1);
   else
       return 1;
}

int main() {
    int n;
    printf("Ingrese un número entero: ");
    scanf("%d",&n);
    printf("Factorial de %d = %ld\n", n, factorial(n));
    return 0;
}
