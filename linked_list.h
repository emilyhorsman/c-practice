struct Node {
    int value;
    struct Node *next;
};

typedef struct Node Node;

Node * _create_node(int value, Node *next);
Node * cons(int value, Node *head);
Node * uncons(Node *head);
Node * reverse_list(Node *head);
void print_list(Node *head);
void free_list(Node *head);
