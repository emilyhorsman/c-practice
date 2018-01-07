#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Vector {
    int i;
    int n;
    int *array;
};


struct Vector * create_vector() {
    struct Vector *vector = (struct Vector *) malloc(sizeof(struct Vector));
    vector->i = 0;
    vector->n = 1;
    vector->array = (int *) malloc(sizeof(int) * vector->n);
    return vector;
}


void free_vector(struct Vector *v) {
    free(v->array);
    free(v);
}


void print_vector_meta(struct Vector *v) {
    printf("Length: %d, Capacity: %d\n", v->i, v->n);
}


void print_vector(struct Vector *v) {
    for (int i = 0; i < v->i; i++) {
        printf("%d ", v->array[i]);
    }
    printf("\n");
}


void _resize_vector(struct Vector *v) {
    assert(v->i < v->n);

    int *array = (int *) malloc(sizeof(int) * v->n);
    memcpy(array, v->array, sizeof(int) * v->i);
    free(v->array);
    v->array = array;
}


void push_vector(struct Vector *v, int value) {
    v->array[v->i++] = value;

    if (v->i > v->n / 2) {
        v->n *= 2;
        _resize_vector(v);
    }
}


int pop_vector(struct Vector *v) {
    int value = v->array[--(v->i)];

    if (v->i < v->n / 2) {
        v->n /= 2;
        _resize_vector(v);
    }

    return value;
}


int main() {
    struct Vector *v = create_vector();
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
