
#include <stdio.h>

int main() {
    int n, x, sum = 0, y;

    printf("Enter a number: ");

    y = n;

    while (n != 0) {
        x = n % 10;
        sum += x * x * x;
        n /= 10;
    }

    if (sum == y)
        printf("%d is an Armstrong number.\n", y);
    else
        printf("%d is not an Armstrong number.\n", y);

    return 0;
}
