#include <limits.h>

int maxSubarraySumCircular(int* nums, int numsSize) {

    int totalSum = 0;

    int maxSum = nums[0], currMax = 0;
    int minSum = nums[0], currMin = 0;

    for(int i = 0; i < numsSize; i++) {

        currMax = (currMax > 0) ? currMax + nums[i] : nums[i];
        maxSum = (currMax > maxSum) ? currMax : maxSum;

        currMin = (currMin < 0) ? currMin + nums[i] : nums[i];
        minSum = (currMin < minSum) ? currMin : minSum;

        totalSum += nums[i];
    }

    // Edge case: all negative
    if(maxSum < 0)
        return maxSum;

    int circular = totalSum - minSum;

    return (maxSum > circular) ? maxSum : circular;
}