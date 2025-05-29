#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Stack for tree nodes
Node* stack[100];
int top = -1;

void push(Node* node) {
    stack[++top] = node;
}

Node* pop() {
    return stack[top--];
}

// Build expression tree from postfix expression
Node* buildTree(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            push(createNode(ch));
        } else { // operator
            Node* node = createNode(ch);
            node->right = pop();
            node->left = pop();
            push(node);
        }
    }
    return pop();
}

// Inorder (infix)
void inorder(Node* root) {
    if (root != NULL) {
        if (root->left && root->right) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (root->left && root->right) printf(")");
    }
}

// Postorder (postfix)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

// Preorder (prefix)
void preorder(Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Evaluate expression tree (only for single-digit operands)
int evaluate(Node* root) {
    if (isdigit(root->data)) return root->data - '0';

    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    return 0;
}

int main() {
    char postfix[100];
    printf("Enter postfix expression (e.g. 34+52-*): ");
    scanf("%s", postfix);

    Node* root = buildTree(postfix);

    printf("\nInfix Expression: ");
    inorder(root);

    printf("\nPrefix Expression: ");
    preorder(root);

    printf("\nPostfix Expression: ");
    postorder(root);

    printf("\nEvaluated Result: %d\n", evaluate(root));

    return 0;
}
