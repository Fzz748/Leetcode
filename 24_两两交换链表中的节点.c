#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 交换链表中相邻节点的位置
 * 
 * @param head 链表的头节点
 * @return 交换后的链表头节点
 */
struct ListNode* swapPairs(struct ListNode* head){
  // 创建一个虚拟头节点，并将其指向原链表的头节点
  struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
  dummyHead->next = head;
  // 创建一个临时节点，用于遍历链表
  struct ListNode* temp = dummyHead;
  // 遍历链表，直到链表末尾或只剩一个节点
  while(temp->next != NULL && temp->next->next != NULL) {
    // 获取需要交换的两个节点
    struct ListNode* node1 = temp->next;
    struct ListNode* node2 = temp->next->next;
    // 进行节点交换
    temp->next = node2;
    node1->next = node2->next;
    node2->next = node1;
    // 更新临时节点的位置
    temp = node1;
  }
  // 返回交换后的链表头节点
  return dummyHead->next;
}

int main() {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = NULL;

    struct ListNode* newHead = swapPairs(head);

    struct ListNode* temp = newHead;
    while(temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}