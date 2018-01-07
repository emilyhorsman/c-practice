#include <stdio.h>
#include "vector.h"


int solve() {
    Vector *stack = create_vector();
    char p, c;
    int ret = 1;
    while ((c = getchar()) != '\n') {
        if (c == '[' || c == '(' || c == '{') {
            push_vector(stack, c);
        } else if (c == ']' || c == ')' || c == '}') {
            p = pop_vector(stack);
            int balancedParen = (
                (p == '[' && c == ']') ||
                (p == '(' && c == ')') ||
                (p == '{' && c == '}')
            );
            if (!balancedParen) {
                ret = 0;
                break;
            }
        }
    }

    ret &= stack->i == 0;

    free_vector(stack);
    return ret;
}


int main() {
    int ret = solve();
    if (ret) {
        printf("Input was balanced.");
    } else {
        printf("Input was imbalanced.");
    }
    return !ret;
}
