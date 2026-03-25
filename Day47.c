#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the height of a binary tree
int height(struct Node* node) {
    // Base case: an empty tree has a height of -1 (or 0, depending on definition)
    // Using -1 here to match the 'edges count' definition
    if (node == NULL) {
        return -1;
    } else {
        // Compute the height of each subtree recursively
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Return the greater of the two heights plus one for the current node/edge
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

// Main function to demonstrate the code
int main() {
    // Constructing a sample tree:
    //      10
    //     /  \
    //    20  30
    //   / \
    //  40 50
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    // Calculate and print the height
    printf("Height of the tree is %d\n", height(root)); // Output: Height of the tree is 2 (edges)

    // Example of a single-node tree
    struct Node* singleNodeRoot = newNode(15);
    printf("Height of the single-node tree is %d\n", height(singleNodeRoot)); // Output: Height is 0 (edges)

    return 0;
}
