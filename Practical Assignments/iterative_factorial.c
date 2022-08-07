#include <stdio.h>
void main() {
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    for (int i = n-1; i > 0; i--){
        n = n * i;
    }
    printf("Factorial = %d\n", n);
}