#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
}*top = NULL;

void push (char x){
     struct Node *t;
     t= (struct Node *)malloc(sizeof(struct Node));
    
     if (t == NULL)
        printf("stack full");
    else {
        t -> data = x;
        t -> next = top;
        top = t;    
    }
}

char pop(){
    struct Node *p;
    int x = -1;
    if (top == NULL)
        printf("stack empty");
    else {
        p = top;
        x = p -> data;
        top = top -> next;
        free(p);
    }
    printf("\n");
    return x;
}

// this is just a simple example eval postfix using stack

int isOperand(char x){
    if (x =='+' || x =='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}

int Evaluate(char *postfix) {
    int i, x1, x2, result;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i]) == 0) {
            x2 = pop();
            x1 = pop();
            switch (postfix[i]) {
                case '+':
                    result = x1 + x2; break;
                case '-':
                    result = x1 - x2; break;
                case '*':
                    result = x1 * x2; break;
                case '/':
                    result = x1 / x2; break;
            }
            push(result);
        } else {
            push(postfix[i] - '0'); 
        }
    }
    return pop();
}


int main() {

    char *postfix = "234*+82/-";

    int result = Evaluate(postfix);
    printf("Result of postfix expression: %d\n", result);
    return 0;
}