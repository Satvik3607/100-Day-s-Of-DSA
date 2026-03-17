#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DO NOT redefine struct ListNode if already given by platform

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while (head != NULL) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    
    // Find middle
    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    struct ListNode* secondHalf = reverseList(slow->next);
    
    // Compare
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalf;
    bool result = true;
    
    while (p2) {
        if (p1->val != p2->val) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    // Restore list
    slow->next = reverseList(secondHalf);
    
    return result;
}