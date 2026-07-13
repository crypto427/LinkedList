/* LinkedList.c */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct LinkedList {
  int size;
  Node *head, *tail;
} LinkedList;

int init_linked_list(LinkedList* list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return 0;
}

int add(void* item, LinkedList* list) {
    Node *node = malloc(sizeof(Node)); // todo this needs to be deallocated later
    node->data = item;
    node->next = NULL;
    if (list->size == 0) {
    	list->head = node;
    }
    else {
    	list->tail->next = node;
    	printf("Here else.");
    }
    list->tail = node;
    list->size++;
    return 0;
}

int main(int argc, char* argv[]) {
    printf("%s\n", argv[0]);
    LinkedList list;
    init_linked_list(&list);
    add((void*)1, &list);
    printf("LinkedList size: %d\n", list.size);
    return 0;
}
