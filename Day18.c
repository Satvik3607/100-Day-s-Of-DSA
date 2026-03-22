#include <stdio.h>

void reverse(int a[], int start, int end) {
    while(start < end) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int k;
    scanf("%d", &k);

    k = k % n;

    reverse(a, 0, n-1);
    reverse(a, 0, k-1);
    reverse(a, k, n-1);

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
