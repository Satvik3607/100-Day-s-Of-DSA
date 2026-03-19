#include <stdlib.h>

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int inorder(int* arr, struct TreeNode* root, int index) {
    if (root != NULL) {
        index = inorder(arr, root->left, index);
        arr[index++] = root->val;
        index = inorder(arr, root->right, index);
    }
    return index;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = countNodes(root);
    int* arr = (int*)malloc(sizeof(int) * size);
    *returnSize = inorder(arr, root, 0);
    return arr;
}