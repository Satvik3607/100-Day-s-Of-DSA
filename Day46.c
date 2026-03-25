#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int* arr, int n, int i) {
    if (i >= n || arr[i] == -1) return NULL;

    struct TreeNode* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

void levelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* curr = queue[front++];
        printf("%d ", curr->val);

        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n, 0);

    levelOrder(root);

    free(arr);
    return 0;
}
