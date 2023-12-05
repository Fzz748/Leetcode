#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
  if (headA == NULL || headB == NULL) {
    return NULL;
  }

  struct ListNode *pA = headA, *pB = headB;

  while (pA != pB) {
    pA = pA == NULL ? headB : pA->next;
    pB = pB == NULL ? headA : pB->next;
  }

  return pA;
}

int main() {
  // 创建相交链表
  struct ListNode *intersectNode = malloc(sizeof(struct ListNode));
  intersectNode->val = 8;
  intersectNode->next = NULL;

  struct ListNode *headA = malloc(sizeof(struct ListNode));
  headA->val = 4;
  headA->next = intersectNode;

  struct ListNode *headB = malloc(sizeof(struct ListNode));
  headB->val = 5;
  headB->next = intersectNode;

  // 调用函数并打印结果
  struct ListNode *result = getIntersectionNode(headA, headB);
  printf("Intersection node value: %d\n", result->val);

  return 0;
}