#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

/**
 * @brief 从链表中移除指定元素的函数
 * 
 * @param head 链表的头指针
 * @param val 要移除的元素值
 * @return struct ListNode* 移除元素后的链表头指针
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
  // 移除链表头部连续的指定元素
  while (head != NULL && head->val == val) {
    struct ListNode* temp = head;
    head = head->next;
    free(temp);
  }
  // 如果链表已经为空，则直接返回
  if (head == NULL) {
    return NULL;
  }
  // 遍历链表，移除中间和尾部的指定元素
  struct ListNode* current = head;
  while (current->next != NULL) {
    if (current->next->val == val) {
      struct ListNode* temp = current->next;
      current->next = current->next->next;
      free(temp);
    } else {
      current = current->next;
    }
  }
  return head;
}

struct ListNode* createNode(int x) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* createList(int* arr, int size) {
    if (size == 0) {
        return NULL;
    }
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // 创建一个链表：1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    struct ListNode* head = createList(arr, sizeof(arr) / sizeof(int));

    // 删除值为6的节点
    struct ListNode* newHead = removeElements(head, 6);

    // 打印新的链表
    struct ListNode* current = newHead;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    // 释放链表的内存
    while (newHead != NULL) {
        struct ListNode* temp = newHead;
        newHead = newHead->next;
        free(temp);
    }

    return 0;
}