#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for level order construction
struct Node* queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

// Create new node
struct Node* createNode(int val) {
    if(val == -1) return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while(i < n) {
        struct Node* current = dequeue();

        // left child
        if(i < n) {
            current->left = createNode(arr[i++]);
            if(current->left != NULL)
                enqueue(current->left);
        }

        // right child
        if(i < n) {
            current->right = createNode(arr[i++]);
            if(current->right != NULL)
                enqueue(current->right);
        }
    }

    return root;
}

// Height function
int height(struct Node* root) {
    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("%d", height(root));

    return 0;
}
