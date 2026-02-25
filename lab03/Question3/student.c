// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // TODO: implement
    if (head == NULL) return false;

    struct ListNode* slowNode = head;
    struct ListNode* fastNode = head->next;

    while (slowNode != NULL && fastNode != NULL) {
        if (slowNode == fastNode) return true;
        slowNode = slowNode->next;
        if (fastNode->next != NULL)
            fastNode = fastNode->next->next;
        else
            return false;
    }

    return false;
}