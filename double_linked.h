#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} *NodePtr;

void InsertAtHead(NodePtr *head_ptr, void *data);
void InsertAtTail(NodePtr *head_ptr, void *data);
void DisplayForward(NodePtr *head_ptr);
NodePtr FindNode(NodePtr *head_ptr, void *data);
void DeleteNodeByData(NodePtr *head_ptr, void *data);

#endif
