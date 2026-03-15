#include <stdio.h>

int main() {
    int n, k;
    int arr[100];
    int comparisons = 0;
    int found = -1;

    // Read array size
    scanf("%d", &n);

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read key
    scanf("%d", &k);

    // Linear Search
    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            found = i;
            break;
        }
    }

    // Output result
    if(found != -1) {
        printf("Found at index %d\n", found);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", comparisons);

    return 0;
}
