#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

/**
 * 寻找环形链表的入口节点
 * 
 * @param head 链表的头节点
 * @return 如果链表中存在环，则返回环的入口节点；否则返回NULL
 */
struct ListNode *detectCycle(struct ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }

  struct ListNode *slow = head, *fast = head;

  // 使用快慢指针法判断链表是否存在环
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      // 如果存在环，将慢指针重新指向头节点，然后慢指针和快指针以相同的速度移动，
      // 直到它们相遇，相遇的节点即为环的入口节点
      slow = head;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }

  return NULL;
}

int main() {
  // 创建带环链表
  struct ListNode *cycleNode = malloc(sizeof(struct ListNode));
  cycleNode->val = 3;
  cycleNode->next = NULL;

  struct ListNode *head = malloc(sizeof(struct ListNode));
  head->val = 2;
  head->next = cycleNode;

  cycleNode->next = head;  // 创建环

  // 调用函数并打印结果
  struct ListNode *result = detectCycle(head);
  if (result != NULL) {
    printf("Cycle detected at node: %d\n", result->val);
  } else {
    printf("No cycle detected.\n");
  }

  return 0;
}
