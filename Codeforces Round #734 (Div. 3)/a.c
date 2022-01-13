#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isPrimeNumber(int n) {
    if (n < 2) {
        return 0;
    }
    int i;
    int squareRoot = sqrt(n);
    for (i = 2; i <= squareRoot; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    int dem = 0;
    int i = 2;
    int a[n];
    while (dem < n) {
        if (isPrimeNumber(i)) {
            a[dem] = i;
            dem++;
        }
        i++;
    }
    printf("%d ", x);
    for (int i = 0; i<n; i++){
        x = x + a[i];
        printf("%d ",x);
    }
}

