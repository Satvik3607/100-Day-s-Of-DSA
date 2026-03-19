#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* q;
    int f;
    int r;
    int n;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = malloc(sizeof(MyCircularDeque));
    obj->n = k + 1;
    obj->q = malloc(sizeof(int) * obj->n);
    obj->f = 0;
    obj->r = 0;
    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if ((obj->r + 1) % obj->n == obj->f) return false;
    obj->f = (obj->f - 1 + obj->n) % obj->n;
    obj->q[obj->f] = value;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if ((obj->r + 1) % obj->n == obj->f) return false;
    obj->q[obj->r] = value;
    obj->r = (obj->r + 1) % obj->n;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->f == obj->r) return false;
    obj->f = (obj->f + 1) % obj->n;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->f == obj->r) return false;
    obj->r = (obj->r - 1 + obj->n) % obj->n;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->f == obj->r) return -1;
    return obj->q[obj->f];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->f == obj->r) return -1;
    return obj->q[(obj->r - 1 + obj->n) % obj->n];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->f == obj->r;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return (obj->r + 1) % obj->n == obj->f;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->q);
    free(obj);
}