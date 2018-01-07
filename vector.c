#include <stdio.h>
#include <stdlib.h>


struct Vector {
    int i;
    int n;
    int *array;
};


struct Vector * create_vector() {
    struct Vector *vector = (struct Vector *) malloc(sizeof(struct Vector));
    vector->i = 0;
    vector->n = 2;
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


void push_vector(struct Vector *v, int value) {
    v->array[v->i++] = value;

    if (v->i > v->n / 2) {
        v->n *= 2;
        int *array = (int *) malloc(sizeof(int) * v->n);
        for (int j = 0; j < v->i; j++) {
            array[j] = v->array[j];
        }
        free(v->array);
        v->array = array;
    }
}


int main() {
    struct Vector *v = create_vector();
    print_vector_meta(v);
    for (int i = 0; i < 64; i++) {
        push_vector(v, i * 10);
        print_vector_meta(v);
    }
    free_vector(v);
}
