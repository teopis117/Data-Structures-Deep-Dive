#include <stdio.h>

int multiplyNumbers(int n1, int n2) {
    if (n1 < n2) {
        return multiplyNumbers(n2, n1);
    }
    else if (n2 != 0) {
        return (n1 + multiplyNumbers(n1, n2 - 1));
    }
    else {
        return 0;
    }
}

int main() {
    int n1,n2;
    printf("Ingrese dos números: ");
    scanf("%d %d",&n1,&n2);
    printf("Producto = %d\n", multiplyNumbers(n1, n2));
    return 0;
}
