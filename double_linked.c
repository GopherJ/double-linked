#include "double_linked.h"

void InsertAtHead(NodePtr *head_ptr, void *data) {
    // Create a new node
    NodePtr new_node = (NodePtr) malloc(sizeof(struct Node));
    new_node -> data = data;

    // Empty list
    if (*head_ptr == NULL) {
        new_node -> prev = NULL;
        new_node -> next = NULL;

        return;
    }

    (*head_ptr) -> prev = new_node;
    new_node -> next = *head_ptr;
    new_node -> prev = NULL;

    // Update list head
    *head_ptr = new_node;
}

void InsertAtTail(NodePtr *head_ptr, void *data) {
    // Create a new node
    NodePtr new_node = (NodePtr) malloc(sizeof(struct Node));
    new_node -> data = data;

    // Tail
    new_node -> next = NULL;

    NodePtr cur_node = *head_ptr;

    // Empty list
    if (*head_ptr == NULL) {
        new_node -> prev = NULL;
        *head_ptr = new_node;

        return;
    }

    // Go to the last node
    while (cur_node -> next != NULL)
        cur_node = cur_node -> next;

    cur_node -> next = new_node;
    new_node -> prev = cur_node;
}

void DisplayForward(NodePtr *head_ptr) {
    if (*head_ptr == NULL) return;
    NodePtr cur_node = *head_ptr;
    printf("%s", (char*)(cur_node -> data));

    while (cur_node -> next != NULL) {
        printf("%s", (char*)(cur_node -> data));
        cur_node = cur_node -> next;
    }
}

NodePtr Search(NodePtr *head_ptr, void *data) {
    NodePtr cur_node = *head_ptr;

    while (cur_node -> next != NULL) {
        if (cur_node -> data != data) break;
        cur_node = cur_node -> next;
    }

    return cur_node;
}

void Delete(NodePtr *head_ptr, void *data) {
    // Empty list
    if (*head_ptr == NULL) return;

    // Find the node with this data
    NodePtr cur_node = *head_ptr;
    while (cur_node != NULL && cur_node -> data != data) {
        cur_node = cur_node -> next;
    }

    // Can't find the data
    if (cur_node == NULL) return;

    // The target node is the head
    if (cur_node -> prev == NULL) {
        // List has just one element
        if (cur_node -> next == NULL) {
            *head_ptr = NULL;
            free(cur_node);

            return;
        }

        cur_node -> next -> prev = NULL;
        cur_node -> next = NULL;

        *head_ptr = cur_node -> next;
    }

    if (cur_node -> next == NULL) {
        cur_node -> prev -> next = NULL;

        free(cur_node);

        return;
    }

    cur_node -> prev -> next = cur_node -> next;
    cur_node -> next -> prev = cur_node -> prev;

    free(cur_node);
}
