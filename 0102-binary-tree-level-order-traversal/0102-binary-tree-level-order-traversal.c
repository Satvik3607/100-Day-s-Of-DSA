#include <stdlib.h>

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int capacity = 16;

    int** result = malloc(sizeof(int*) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);

    struct TreeNode** queue = malloc(sizeof(struct TreeNode*) * capacity);
    int front = 0, rear = 0;

    queue[rear++] = root;
    int levelCount = 0;

    while (front < rear) {
        int size = rear - front;

        if (levelCount >= capacity) {
            capacity *= 2;
            result = realloc(result, sizeof(int*) * capacity);
            *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * capacity);
        }

        result[levelCount] = malloc(sizeof(int) * size);
        (*returnColumnSizes)[levelCount] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            result[levelCount][i] = node->val;

            if (node->left) {
                if (rear >= capacity) {
                    capacity *= 2;
                    queue = realloc(queue, sizeof(struct TreeNode*) * capacity);
                }
                queue[rear++] = node->left;
            }

            if (node->right) {
                if (rear >= capacity) {
                    capacity *= 2;
                    queue = realloc(queue, sizeof(struct TreeNode*) * capacity);
                }
                queue[rear++] = node->right;
            }
        }

        levelCount++;
    }

    *returnSize = levelCount;
    free(queue);
    return result;
}