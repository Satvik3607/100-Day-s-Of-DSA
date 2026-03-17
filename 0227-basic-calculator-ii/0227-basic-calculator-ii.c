#include <stdlib.h>

int calculate(char* s) {
    int len = 0;
    while (s[len] != '\0') len++;

    int* stack = (int*)malloc(len * sizeof(int));
    int top = -1;

    char op = '+';
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == ' ') {
            i++;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            op = s[i];
            i++;
        }
        else {
            int num = 0;

            while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            if (op == '+') {
                stack[++top] = num;
            }
            else if (op == '-') {
                stack[++top] = -num;
            }
            else if (op == '*') {
                stack[top] = stack[top] * num;
            }
            else if (op == '/') {
                stack[top] = stack[top] / num;
            }
        }
    }

    int result = 0;
    while (top >= 0) {
        result += stack[top--];
    }

    free(stack);
    return result;
}