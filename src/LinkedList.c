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

int init_linked_list(LinkedList *list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return 0;
}

int add(void *item, LinkedList *list) {
    Node *node = malloc(sizeof(Node));
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

Node *get(int index, LinkedList *list) {
    Node *on = list->head;
    int i = 0;
    while(i < index) {
        on = on->next;
        i++;
    }
    if(on != NULL)
        printf("%p\n", on->data);
    return on;
}

int deleteList(LinkedList *list) {
    Node *on = list->head;
    Node *next;
    while(on != NULL){
         next = on->next;
         free(on->data);
         free(on);
         on = next;
         list->size--;
    }
    return 0;
}

void printList(LinkedList *list) {
    Node *on = list->head;
    printf("Printing list:\n");
    while(on != NULL) {
        printf("[data: %d ]->next => ", *(int*)on->data); // Temporary, fix this immediately
        on = on->next;
    }
    printf("NULL \n");
}

int main(int argc, char* argv[]) {
    printf("%s\n", argv[0]);
    LinkedList list;
    init_linked_list(&list);
    int *myInt = malloc(sizeof(int));
    if(myInt == NULL) {
        deleteList(&list);
        return -1;
    }
    *myInt = 50;
    add((void*)myInt, &list);
    printf("LinkedList size: %d\n", list.size);
    int *retrieved = (int*)get(0, &list)->data;
    printf("LL(0) = %d\n", *retrieved); 
    printList(&list);
    deleteList(&list);
    printf("LinkedList size: %d\n", list.size);
    return 0;
}
