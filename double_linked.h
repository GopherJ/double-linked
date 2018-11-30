#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} *NodePtr;


void InsertAtHead(NodePtr *head_ptr, void *data);
void InsertAtTail(NodePtr *head_ptr, void *data);
void DisplayForward(NodePtr *head_ptr);
NodePtr Search(NodePtr *head_ptr, void *data);
void Delete(NodePtr *head_ptr, void *data);
