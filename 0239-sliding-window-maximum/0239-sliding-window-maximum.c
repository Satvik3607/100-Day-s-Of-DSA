#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int* deque = (int*)malloc(sizeof(int) * numsSize);

    int front = 0, rear = -1;
    int resIndex = 0;

    for (int i = 0; i < numsSize; i++) {
        if (front <= rear && deque[front] <= i - k)
            front++;

        while (front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        deque[++rear] = i;

        if (i >= k - 1)
            result[resIndex++] = nums[deque[front]];
    }

    *returnSize = resIndex;

    free(deque);
    return result;
}