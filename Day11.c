#include <stdio.h>

int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    int A[100][100], B[100][100], C[100][100];

    // Read first matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read second matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Add matrices
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print result
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
