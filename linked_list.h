#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_


#define container_of(list_pointer, container_type, list_member_name) (         \
        (container_type *)                                                     \
        ((void *) list_pointer - offsetof(container_type, list_member_name)))


#define list_next(container, list_member_name)                                 \
        &container->list_member_name == NULL ? NULL :                          \
            container_of(container->list_member_name.next,                     \
                         typeof(*container), list_member_name)


#define for_each_container(container, list_member_name)                        \
        for (;                                                                 \
             &container->list_member_name != NULL;                             \
             container = list_next(container, list_member_name))


#define for_each_container_safe(container, next, list_member_name)             \
        for (next = list_next(container, list_member_name);                    \
             &container->list_member_name != NULL;                             \
             container = next, next = list_next(container, list_member_name))


struct Node {
    struct Node *next;
};

typedef struct Node Node;

Node * reverse_list(Node *head);


#endif
