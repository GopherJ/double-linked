#include <stdio.h>
#include <stdlib.h>

#include "double_linked.h"

int main(void) {
    NodePtr head = NULL;

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;

    printf("\nTest1 - InsertAtTail\n");
    InsertAtTail(&head, &c);
    InsertAtTail(&head, &d);
    InsertAtTail(&head, &e);
    InsertAtHead(&head, &b);
    InsertAtHead(&head, &a);

    DisplayForward(&head);

    printf("\nTest2 - FindNode\n");
    NodePtr node = FindNode(&head, &c);
    printf("%d", *(int*)(node -> data));

    printf("\nTest3 - DeleteNodeByData\n");
    DeleteNodeByData(&head, &c);
    DisplayForward(&head);

    printf("\nTest4 - DeleteNodeByData\n");
    DeleteNodeByData(&head, &a);
    DisplayForward(&head);
}