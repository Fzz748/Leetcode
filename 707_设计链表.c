#include <stdio.h>
#include <stdlib.h>


typedef struct {
  int val;
  struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *Linklist = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    Linklist->next = NULL;
    return Linklist;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
  MyLinkedList *p = obj;
  for (int i = 0; i < index; i++) {
    p = p->next;
    if(p == NULL) 
      return -1;
  }
  return p->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  MyLinkedList* newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
  newNode->val = val;
  newNode->next = obj->next;
  obj->next = newNode;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
  MyLinkedList* newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
  newNode->val = val;
  newNode->next = NULL;
  while (obj->next)
  {
    obj = obj->next;
  }
  obj->next = newNode; 
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
  MyLinkedList* newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
  newNode->val = val;
  newNode->next = NULL;
  while (obj && index--)
  {
    obj = obj->next;
  }
  if (obj)
  {
    newNode = obj->next;
    obj->next = newNode;
  }
  
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
  while (obj && index--)
  {
    obj = obj->next;
  }
  if (obj && obj->next)
  {
    MyLinkedList *delNode = obj->next;
    obj->next = delNode->next;
    free(delNode);
  }
}

void myLinkedListFree(MyLinkedList *obj)
{
  while (obj != NULL)
  {
    MyLinkedList *tmp = obj;
    obj = obj->next;
    free(tmp);
  }
}

int main() {
    MyLinkedList* obj = myLinkedListCreate();
    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtTail(obj, 3);
    myLinkedListAddAtIndex(obj, 1, 2);
    printf("Value at index 1: %d\n", myLinkedListGet(obj, 1)); // 应该输出2
    myLinkedListDeleteAtIndex(obj, 1);
    printf("Value at index 1: %d\n", myLinkedListGet(obj, 1)); // 应该输出3
    return 0;
}