#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Function to return precedence of operators */
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

/* Check if operator is right associative */
int isRightAssociative(char c) {
    return c == '^';
}

/* Function to convert infix expression to postfix */
void infixToPostfix(char* exp) {
    int len = strlen(exp);        // a+b+c = 5
    char result[len + 1];         // 5 + 1 = '\0'
    char stack[len];
    int j = 0;
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = exp[i];

        // If operand, add to result
        if (isalnum(c)) {
            result[j++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            stack[++top] = c;
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = stack[top--];
            }
            top--; // pop '('
        }
        // If operator
        else {
            while (top != -1 && stack[top] != '(' &&
                  (prec(stack[top]) > prec(c) ||
                  (prec(stack[top]) == prec(c) && !isRightAssociative(c)))) {
                result[j++] = stack[top--];
            }
            stack[++top] = c;   // push operator
        }
    }

    // Pop remaining operators
    while (top != -1) {
        result[j++] = stack[top--];
    }

    result[j] = '\0';
    printf("%s\n", result);
}

/* Main function */
int main() {
    char exp1[] = "a*(b+c)/d";
    infixToPostfix(exp1);
    return 0;
}
