#include <stdlib.h>
#include <stdbool.h>

struct MyQueue {
    int* stack1;
    int* stack2;
    int top1;
    int top2;
    int capacity;
};

typedef struct MyQueue MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = malloc(sizeof(MyQueue));
    obj->capacity = 1000;
    obj->stack1 = malloc(obj->capacity * sizeof(int));
    obj->stack2 = malloc(obj->capacity * sizeof(int));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    while (obj->top1 != -1) {
        obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
    }

    int removed = obj->stack2[obj->top2--];

    while (obj->top2 != -1) {
        obj->stack1[++obj->top1] = obj->stack2[obj->top2--];
    }

    return removed;
}

int myQueuePeek(MyQueue* obj) {
    while (obj->top1 != -1) {
        obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
    }

    int front = obj->stack2[obj->top2];

    while (obj->top2 != -1) {
        obj->stack1[++obj->top1] = obj->stack2[obj->top2--];
    }

    return front;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}