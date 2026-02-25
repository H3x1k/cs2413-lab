// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    // TODO: implement
    if (head == NULL) return 0;
    if (head->next == NULL) return head->val;

    struct ListNode* slowNode = head;
    struct ListNode* fastNode = head->next;

    while (fastNode->next != NULL) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;

        if (fastNode == NULL) {
            return slowNode->val;
        }
    }

    return slowNode->next->val;

}