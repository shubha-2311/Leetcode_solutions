#include <stdio.h>

int smallestNumber(int n) {
    int res = 1;
    while (n > 0) {
        res *= 2;
        n /= 2;
    }
    return res - 1;
}

int main() {
    int n;
    printf("\nEnter the number: ");
    scanf("%d",&n);
    int result = smallestNumber(n);
    printf("Smallest number with all bits 1 for n=%d is: %d\n", n, result);
    return 0;
}
