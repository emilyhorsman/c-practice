#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


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
struct Container {
    char *name;
    int id;
    Node list;
};
typedef struct Container Container;


void print_containers(Container *container) {
    for_each_container(container, list) {
        printf("%s %d\n", container->name, container->id);
    }
}


int main() {
    Container a = { "a", 0, { NULL } },
              b = { "b", 1, { NULL } },
              c = { "c", 2, { NULL } };
    a.list.next = &b.list;
    b.list.next = &c.list;

    Node *head = &a.list;

    printf("a is at %p\n", &a);
    printf("a.list is at %p\n", &a.list);
    printf("sizeof(Container) = %lu, sizeof(Node) = %lu\n", sizeof(Container), sizeof(Node));
    printf("Difference between the two is %ld\n", (void *) &a.list - (void *) &a);
    printf("a is computed to be at: %p (1)\n", (void *) &a.list - (sizeof(Container) - sizeof(Node)));
    printf("a is computed to be at: %p (2)\n", (void *) head - (sizeof(Container) - sizeof(Node)));
    // The above will only work if the Node is last member of the struct.
    // Using offsetof will work wherever the member is:
    printf("a is computed to be at: %p (3)\n", (void *) head - offsetof(Container, list));
    printf("a is computed to be at: %p (4)\n", container_of(head, Container, list));

    Container *cur = container_of(head, Container, list);
    printf("%d %s\n", cur->id, cur->name);
    cur = container_of(head->next, Container, list);
    printf("%d %s\n", cur->id, cur->name);
    printf("-----\n");

    print_containers(&a);
    head = reverse_list(head);
    printf("-----\n");
    print_containers(&c);
    free_containers(&c);
}
#endif
