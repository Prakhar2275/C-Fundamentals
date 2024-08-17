#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Function to evaluate the expression
double evaluate(const char *expression);

// Helper function to get the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Function to perform arithmetic operations
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

// Function to evaluate a simple expression without parentheses
double evaluateSimple(const char *expression) {
    double values[100];
    char ops[100];
    int valuesTop = -1;
    int opsTop = -1;

    for (int i = 0; expression[i]; i++) {
        if (isspace(expression[i])) {
            continue;
        }

        if (isdigit(expression[i])) {
            double value = 0;
            while (i < strlen(expression) && isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            values[++valuesTop] = value;
        } else if (expression[i] == '(') {
            ops[++opsTop] = expression[i];
        } else if (expression[i] == ')') {
            while (opsTop != -1 && ops[opsTop] != '(') {
                double val2 = values[valuesTop--];
                double val1 = values[valuesTop--];
                char op = ops[opsTop--];
                values[++valuesTop] = applyOp(val1, val2, op);
            }
            opsTop--; // Remove '('
        } else {
            while (opsTop != -1 && precedence(ops[opsTop]) >= precedence(expression[i])) {
                double val2 = values[valuesTop--];
                double val1 = values[valuesTop--];
                char op = ops[opsTop--];
                values[++valuesTop] = applyOp(val1, val2, op);
            }
            ops[++opsTop] = expression[i];
        }
    }

    while (opsTop != -1) {
        double val2 = values[valuesTop--];
        double val1 = values[valuesTop--];
        char op = ops[opsTop--];
        values[++valuesTop] = applyOp(val1, val2, op);
    }

    return values[valuesTop];
}

// Function to remove trailing '=' sign and evaluate the expression
double evaluate(const char *expression) {
    size_t length = strlen(expression);
    if (expression[length - 1] == '=') {
        char *expr = malloc(length);
        strncpy(expr, expression, length - 1);
        expr[length - 1] = '\0';
        double result = evaluateSimple(expr);
        free(expr);
        return result;
    } else {
        return evaluateSimple(expression);
    }
}

int main() {
    char expression[256];
    int numExpressions;

    printf("Enter the number of expressions: ");
    scanf("%d", &numExpressions);
    getchar();  // Consume the newline character after the number of expressions

    for (int i = 0; i < numExpressions; i++) {
        printf("Enter expression %d: ", i + 1);
        fgets(expression, sizeof(expression), stdin);
        // Remove the newline character from fgets
        expression[strcspn(expression, "\n")] = '\0';

        double result = evaluate(expression);
        printf("Result: %f\n", result);
    }

    return 0;
}
