  while(obj != NULL){
      MyLinkedList *tmp = obj;
      obj = obj->next;
      free(tmp);
  }