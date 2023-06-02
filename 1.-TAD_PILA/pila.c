#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    char data;
    struct Nodo* next;
} Nodo;

void push(Nodo** top_ref, char new_data);
char pop(Nodo** top_ref);

int esPalindromo(char* str) {
    Nodo* stack = NULL;

    int i;
    for (i = 0; i < strlen(str); i++)
        push(&stack, str[i]);

    for (i = 0; i < strlen(str); i++) {
        if (pop(&stack) != str[i])
            return 0;
    }
    return 1;
}

void push(Nodo** top_ref, char new_data) {
    Nodo* new_node = (Nodo*)malloc(sizeof(Nodo));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

char pop(Nodo** top_ref) {
    char res;
    Nodo* top;

    top = *top_ref;
    res = top->data;
    *top_ref = top->next;
    free(top);

    return res;
}

int main() {
    char str[] = "reconocer";
    if (esPalindromo(str))
        printf("Sí\n");
    else
        printf("No\n");
    return 0;
}
