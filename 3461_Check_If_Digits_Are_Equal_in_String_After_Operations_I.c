#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

bool hasSameDigits(char* s) {
    int n = strlen(s);
    while (n > 2) {
        for (int i = 1; i < n; i++) {
            s[i - 1] = (s[i] + s[i - 1]) % 10;
        }
        n--;
    }
    if (n == 2 && s[0] == s[1])
        return true;
    return false;
}

int main() {
    char s[MAX];
    printf("\nEnter the integer string: ");
    scanf("%s",s);
    if (hasSameDigits(s))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
