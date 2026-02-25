// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement

      if (head == NULL) return NULL;
      else if (head->next == NULL) return head;

      struct ListNode* newHead = head->next;

      struct ListNode* nextNode = head;
      struct ListNode* lastNode = NULL;

      while (nextNode != NULL && nextNode->next != NULL) {
            struct ListNode* firstNode = nextNode;
            struct ListNode* secondNode = nextNode->next;
            nextNode = secondNode->next;

            secondNode->next = firstNode;
            firstNode->next = nextNode;
            if (lastNode != NULL) lastNode->next = secondNode;

            lastNode = firstNode;
      }

      return newHead;
}