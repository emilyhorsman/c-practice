#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"


Vector * create_vector() {
    Vector *vector = (Vector *) malloc(sizeof(Vector));
    vector->i = 0;
    vector->n = 1;
    vector->array = (int *) malloc(sizeof(int) * vector->n);
    return vector;
}


void free_vector(Vector *v) {
    free(v->array);
    free(v);
}


void print_vector_meta(Vector *v) {
    printf("Length: %d, Capacity: %d\n", v->i, v->n);
}


void print_vector(Vector *v) {
    for (int i = 0; i < v->i; i++) {
        printf("%d ", v->array[i]);
    }
    printf("\n");
}


void _resize_vector(Vector *v) {
    assert(v->i < v->n);

    int *array = (int *) malloc(sizeof(int) * v->n);
    memcpy(array, v->array, sizeof(int) * v->i);
    free(v->array);
    v->array = array;
}


void push_vector(Vector *v, int value) {
    v->array[v->i++] = value;

    if (v->i > v->n / 2) {
        v->n *= 2;
        _resize_vector(v);
    }
}


int pop_vector(Vector *v) {
    int value = v->array[--(v->i)];

    if (v->i < v->n / 2) {
        v->n /= 2;
        _resize_vector(v);
    }

    return value;
}


#ifdef _VECTOR_MAIN_
int main() {
    Vector *v = create_vector();
    print_vector_meta(v);
    for (int i = 0; i < 64; i++) {
        push_vector(v, i * 10);
        print_vector_meta(v);
    }

    for (int i = 0; i < 64; i++) {
        pop_vector(v);
        print_vector_meta(v);
    }

    free_vector(v);
}
#endif
