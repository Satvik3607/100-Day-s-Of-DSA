#include <stdlib.h>

typedef struct {
    int key;
    int freq;
} HashNode;

typedef struct {
    int freq;
    int val;
} HeapNode;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(HeapNode* heap, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].freq > heap[i].freq) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapifyDown(HeapNode* heap, int size, int i) {
    while (1) {
        int smallest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < size && heap[l].freq < heap[smallest].freq)
            smallest = l;

        if (r < size && heap[r].freq < heap[smallest].freq)
            smallest = r;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    HashNode* hash = malloc(sizeof(HashNode) * numsSize);
    int hashSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int found = -1;
        for (int j = 0; j < hashSize; j++) {
            if (hash[j].key == nums[i]) {
                found = j;
                break;
            }
        }
        if (found == -1) {
            hash[hashSize].key = nums[i];
            hash[hashSize].freq = 1;
            hashSize++;
        } else {
            hash[found].freq++;
        }
    }

    HeapNode* heap = malloc(sizeof(HeapNode) * k);
    int heapSize = 0;

    for (int i = 0; i < hashSize; i++) {
        if (heapSize < k) {
            heap[heapSize].freq = hash[i].freq;
            heap[heapSize].val = hash[i].key;
            heapifyUp(heap, heapSize);
            heapSize++;
        } 
        else if (hash[i].freq > heap[0].freq) {
            heap[0].freq = hash[i].freq;
            heap[0].val = hash[i].key;
            heapifyDown(heap, heapSize, 0);
        }
    }

    int* result = malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        result[i] = heap[i].val;
    }

    *returnSize = k;

    free(hash);
    free(heap);

    return result;
}