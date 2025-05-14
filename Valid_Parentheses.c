#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->arr[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';
}

bool isValid(char *s) {
    Stack stack;
    initialize(&stack);
    
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&stack, c);
        } else {
            if (isEmpty(&stack)) {
                return false;
            }
            char top = pop(&stack);
            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    
    return isEmpty(&stack);
}

int main() {
    char input[MAX_SIZE];
    
    printf("Enter a string of parentheses: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; 
    
    if (isValid(input)) {
        printf("The parentheses are valid.\n");
    } else {
        printf("The parentheses are NOT valid.\n");
    }
    
    return 0;
}