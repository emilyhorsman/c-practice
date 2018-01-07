#include <stdio.h>
#include <stdlib.h>


struct Node {
    int value;
    struct Node *next;
};


struct Node * _create_node(int value, struct Node *next) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->next = next;
    return node;
}


struct Node * cons(int value, struct Node *head) {
    struct Node *node = _create_node(value, head);
    return node;
}


struct Node * uncons(struct Node *head) {
    struct Node *h = head->next;
    free(head);
    return h;
}


void print_list(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}


void free_list(struct Node *head) {
    while (head != NULL) {
        head = uncons(head);
    }
}


struct Node * reverse_list(struct Node *head) {
    if (head->next == NULL) {
        return head;
    }

    struct Node *new = reverse_list(head->next);
    struct Node *cur = new;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = head;
    head->next = NULL;
    return new;
}


struct Node * reverse_list2(struct Node *head) {
    if (head->next == NULL) {
        return head;
    }

    struct Node *new = reverse_list2(head->next);
    head->next->next = head;
    head->next = NULL;

    return new;
}


struct Node * reverse_list3(struct Node *head) {
    struct Node *temp, *prev = NULL;
    while (head != NULL) {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}


int main() {
    struct Node *head = cons(5, cons(4, cons(3, cons(2, cons(1, _create_node(0, NULL))))));
    print_list(head);
    head = reverse_list3(head);
    print_list(head);
    free_list(head);
}
