#ifndef _VECTOR_H_
#define _VECTOR_H_


struct Vector {
    int i;
    int n;
    int *array;
};

typedef struct Vector Vector;

Vector * create_vector();
void free_vector(Vector *v);
void push_vector(Vector *v, int value);
int pop_vector(Vector *v);


#endif
