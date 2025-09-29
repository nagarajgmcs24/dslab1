#include <stdio.h>
#include <ctype.h> // for isalnum()
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push element onto stack
void push(char x) {
    stack[++top] = x;
}

// Pop element from stack
char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Check precedence of operators
int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return -1;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char ch;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            // Operand → directly add to postfix
            postfix[k++] = ch;
        } 
        else if (ch == '(') {
            push(ch);
        } 
        else if (ch == ')') {
            // Pop until '('
            while ((stack[top] != '(') && (top != -1)) {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        } 
        else { 
            // Operator
            while (precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}