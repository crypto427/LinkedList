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
    if (!list)
        return -1;
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return 0;
}

int add(void *item, LinkedList *list) {
    if (!list)
        return -1;
    
    Node *node = malloc(sizeof(Node));
    if (!node)
        return -1;
    node->data = item;
    node->next = NULL;
    if (list->size == 0) {
    	list->head = node;
    }
    else {
    	list->tail->next = node;
    }
    list->tail = node;
    list->size++;
    return 0;
}

Node *get(int index, LinkedList *list) {
    if (!list || index < 0 || index >= list->size)
        return NULL;
    Node *on = list->head;
    int i = 0;
    while(i < index && on != NULL) {
        on = on->next;
        i++;
    }
    if(on != NULL)
        printf("%p\n", on->data);
    return on;
}

void deleteList(LinkedList *list, void (*free_data)(void *)) {
    if (!list)
        return;
    Node *on = list->head;
    Node *next;
    while(on != NULL){
         next = on->next;
         if (free_data && on->data) {
            free_data(on->data);
         }
         free(on);
         on = next;
         list->size--;
    }
    
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void printList(LinkedList *list) {
    Node *on = list->head;
    printf("Printing list:\n");
    while(on != NULL) {
        printf("[data: %d ]->next => ", *(int*)on->data); // Temporary, tightly coupled
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
        deleteList(&list, free);
        return -1;
    }
    *myInt = 50;
    if (add(myInt, &list) == -1) {
        free(myInt);
        return -1;
    }
    printf("LinkedList size: %d\n", list.size);
    Node *node = get(0, &list);
    int *retrieved = NULL;
    if (node) {
        retrieved = node->data;
        printf("LL(0) = %d\n", *retrieved);
    } 
    printList(&list);
    deleteList(&list, free);
    printf("LinkedList size: %d\n", list.size);
    return 0;
}
