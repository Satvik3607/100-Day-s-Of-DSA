#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    int* result = (int*)malloc(numsSize * sizeof(int));

    result[0] = 1;

    // Prefix
    for(int i = 1; i < numsSize; i++) {
        result[i] = result[i-1] * nums[i-1];
    }

    int suffix = 1;

    // Suffix
    for(int i = numsSize - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    *returnSize = numsSize;
    return result;
}