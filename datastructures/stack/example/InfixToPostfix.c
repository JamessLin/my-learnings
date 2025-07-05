#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
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
    char x = -1;
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

// this is just a simple example of infix to postfix conversion using stack

int precedence(char x) {
    if (x=='+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/') {
        return 2;
    }
    return 0;
}

int isOperand(char x){
    if (x =='+' || x =='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}

char *infixToPostfix(char *infix) {
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 1) * sizeof(char));
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            while (top != NULL && precedence(top->data) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }

    while (top != NULL) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the string
    return postfix;
}

int main() {

    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix = infixToPostfix(infix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}