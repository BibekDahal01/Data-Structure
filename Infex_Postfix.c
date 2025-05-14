#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
} s;

// Function to initialize stack
void initStack() {
    s.top = -1;
}

// Function to check if stack is empty
int isEmpty() {
    return s.top == -1;
}

// Function to push an element onto the stack
void push(char c) {
    if (s.top < MAX - 1) {
        s.arr[++s.top] = c;
    }
}

// Function to pop an element from the stack
char pop() {
    return isEmpty() ? '\0' : s.arr[s.top--];
}

// Function to peek the top element of the stack
char peek() {
    return isEmpty() ? '\0' : s.arr[s.top];
}

// Function to get operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    initStack();
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) { // Operand directly added to result
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') { // Push '(' onto stack
            push(infix[i]);
        } else if (infix[i] == ')') { // Pop until '(' is found
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        } else { // Operator case
            while (!isEmpty() && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    // Pop remaining operators from stack
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null terminate the string
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    // User input
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Output result
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
