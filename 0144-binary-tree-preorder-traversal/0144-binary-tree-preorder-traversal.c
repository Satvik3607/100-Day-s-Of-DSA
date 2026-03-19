#include <stdlib.h>

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int preorder(int* arr, struct TreeNode* root, int index) {
    if (root != NULL) {
        arr[index++] = root->val;
        index = preorder(arr, root->left, index);
        index = preorder(arr, root->right, index);
    }
    return index;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = countNodes(root);
    int* arr = (int*)malloc(sizeof(int) * size);
    *returnSize = preorder(arr, root, 0);
    return arr;
}