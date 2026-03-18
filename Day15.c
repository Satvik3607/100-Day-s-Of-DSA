#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int sum = 0;

    // Only works properly if square or min(m,n)
    for(int i = 0; i < m && i < n; i++) {
        sum += a[i][i];
    }

    printf("%d", sum);

    return 0;
}
