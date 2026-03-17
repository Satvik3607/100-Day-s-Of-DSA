#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 1000; // initial capacity
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    int k = 0;

    for(int i = 0; i < numsSize - 2; i++) {

        // skip duplicates for i
        if(i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while(left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0) {

                // resize if needed
                if(k >= capacity) {
                    capacity *= 2;
                    result = realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                result[k] = (int*)malloc(3 * sizeof(int));
                result[k][0] = nums[i];
                result[k][1] = nums[left];
                result[k][2] = nums[right];

                (*returnColumnSizes)[k] = 3;
                k++;

                // skip duplicates for left
                while(left < right && nums[left] == nums[left + 1])
                    left++;

                // skip duplicates for right
                while(left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if(sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    *returnSize = k;
    return result;
}