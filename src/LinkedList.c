/* LinkedList.c */

#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
  int size;
  Node *head, *tail;
} LinkedList;

int main(int argc, char* argv[])
{
    printf("%s\n", argv[0]);
    return 0;
}
