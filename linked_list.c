#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


Node * _create_node(int value, Node *next) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}


Node * cons(int value, Node *head) {
    Node *node = _create_node(value, head);
    return node;
}


Node * uncons(Node *head) {
    Node *h = head->next;
    free(head);
    return h;
}


void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}


void free_list(Node *head) {
    while (head != NULL) {
        head = uncons(head);
    }
}


Node * reverse_list(Node *head) {
    Node *temp, *prev = NULL;
    while (head != NULL) {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}


#ifdef _LINKED_LIST_MAIN_
int main() {
    Node *head = cons(5, cons(4, cons(3, cons(2, cons(1, _create_node(0, NULL))))));
    print_list(head);
    head = reverse_list(head);
    print_list(head);
    free_list(head);
}
#endif
