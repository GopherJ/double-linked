#include <stdio.h>
#include <stdlib.h>
#include "double_linked.h"

int main(void) {
    NodePtr head = NULL;

    int a = 1;
    char b = 'c';
    float c = 1.0;

    InsertAtTail(&head, &a);
    InsertAtTail(&head, &b);
    InsertAtTail(&head, &c);

    DisplayForward(&head);
}