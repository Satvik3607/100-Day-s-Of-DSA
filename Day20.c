#include <stdio.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int a[1000];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int prefixSum = 0;
    int count = 0;

    int freq[2 * MAX + 1] = {0}; // handle negative sums
    int offset = MAX;

    freq[offset] = 1; // prefixSum = 0 initially

    for(int i = 0; i < n; i++) {
        prefixSum += a[i];

        if(freq[prefixSum + offset] > 0)
            count += freq[prefixSum + offset];

        freq[prefixSum + offset]++;
    }

    printf("%d", count);

    return 0;
}
