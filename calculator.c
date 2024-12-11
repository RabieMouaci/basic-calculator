#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

// Stack structure for numbers
typedef struct {
    double data[MAX];
    int top;
} Stack;

// Stack operations
void push(Stack *s, double value) {
    s->data[++(s->top)] = value;
}

double pop(Stack *s) {
    return s->data[(s->top)--];
}

// Check operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Check if character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Evaluate a binary operation
double evaluate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

// Convert infix to postfix using Shunting-Yard algorithm
void infixToPostfix(char *infix, char postfix[][MAX]) {
    char stack[MAX];
    int top = -1, j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        if (isdigit(infix[i]) || infix[i] == '.') { // Number
            int k = 0;
            while (isdigit(infix[i]) || infix[i] == '.') {
                postfix[j][k++] = infix[i++];
            }
            postfix[j++][k] = '\0';
            i--;
        } else if (infix[i] == '(') { // Left parenthesis
            stack[++top] = infix[i];
        } else if (infix[i] == ')') { // Right parenthesis
            while (top >= 0 && stack[top] != '(') {
                sprintf(postfix[j++], "%c", stack[top--]);
            }
            top--; // Pop '('
        } else if (isOperator(infix[i])) { // Operator
            while (top >= 0 && precedence(stack[top]) >= precedence(infix[i])) {
                sprintf(postfix[j++], "%c", stack[top--]);
            }
            stack[++top] = infix[i];
        }
    }

    while (top >= 0) { // Pop remaining operators
        sprintf(postfix[j++], "%c", stack[top--]);
    }
}

// Evaluate postfix expression
double evaluatePostfix(char postfix[][MAX], int size) {
    Stack s = {.top = -1};

    for (int i = 0; i < size; i++) {
        if (isdigit(postfix[i][0]) || (postfix[i][0] == '-' && isdigit(postfix[i][1]))) { // Number
            push(&s, atof(postfix[i]));
        } else { // Operator or function
            double b = pop(&s);
            double a = pop(&s);
            push(&s, evaluate(a, b, postfix[i][0]));
        }
    }

    return pop(&s);
}

int main() {
    char infix[MAX], postfix[MAX][MAX];

    printf("Enter an expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline

    int size = 0;

    // Convert to postfix notation
    infixToPostfix(infix, postfix);

    // Count number of tokens in postfix array
    while (*postfix[size]) size++;

    // Evaluate the postfix expression
    double result = evaluatePostfix(postfix, size);

    printf("Result: %.6lf\n", result);

    return 0;
}