
#include <stdio.h>
#include <stdlib.h>


struct ArrStack {
    int  top;
    int  size;
    int *S;
};


void arr_create(struct ArrStack *st)
{
    printf("Enter size of array stack: ");
    scanf("%d", &st->size);

    st->top = -1;
    st->S   = malloc(st->size * sizeof *st->S);
    if (!st->S) {
        fprintf(stderr, "Malloc failed – exiting.\n");
        exit(EXIT_FAILURE);
    }
}

int  arr_isEmpty(struct ArrStack st) { return st.top == -1; }
int  arr_isFull (struct ArrStack st) { return st.top == st.size - 1; }

void arr_push(struct ArrStack *st, int x)
{
    if (arr_isFull(*st))
        printf("Array stack overflow\n");
    else
        st->S[++st->top] = x;
}

int arr_pop(struct ArrStack *st)
{
    if (arr_isEmpty(*st)) {
        printf("Array stack underflow\n");
        return -1;
    }
    return st->S[st->top--];
}

int arr_peek(struct ArrStack st, int i)
{
    int idx = st.top - i + 1;
    if (idx < 0) {
        printf("Invalid index for array stack\n");
        return -1;
    }
    return st.S[idx];
}

void arr_display(struct ArrStack st)
{
    for (int i = st.top; i >= 0; --i)
        printf("%d ", st.S[i]);
    putchar('\n');
}


struct Node {
    int          data;
    struct Node *next;
};

struct Node *list_top = NULL;       

int  list_isEmpty(void) { return list_top == NULL; }

void list_push(int x)
{
    struct Node *t = malloc(sizeof *t);
    if (!t) {
        printf("Linked-list stack overflow\n");
        return;
    }
    t->data = x;
    t->next = list_top;
    list_top = t;
}

int list_pop(void)
{
    if (list_isEmpty()) {
        printf("Linked-list stack underflow\n");
        return -1;
    }
    struct Node *p = list_top;
    int           x = p->data;
    list_top       = list_top->next;
    free(p);
    return x;
}

void list_display(void)
{
    for (struct Node *p = list_top; p; p = p->next)
        printf("%d ", p->data);
    putchar('\n');
}


int main(void)
{
    struct ArrStack aSt;
    arr_create(&aSt);

    arr_push(&aSt, 10);
    arr_push(&aSt, 11);
    arr_push(&aSt, 12);

    printf("\nArray stack contents: ");
    arr_display(aSt);                 /* 12 11 10 */

    printf("Array stack pop:  %d\n", arr_pop(&aSt));       /* 12 */
    printf("Peek index 2:     %d\n", arr_peek(aSt, 2));    /* 10 */
    printf("Is empty?  %s\n", arr_isEmpty(aSt)? "Yes":"No");
    printf("Is full?   %s\n", arr_isFull(aSt)?  "Yes":"No");

    printf("Array stack now:  ");
    arr_display(aSt);                 /* 11 10 */
    free(aSt.S);                      /* tidy up */


    list_push(20);
    list_push(30);
    list_push(40);

    printf("\nLinked-list stack contents: ");
    list_display();                   /* 40 30 20 */

    printf("Linked-list pop:  %d\n", list_pop());          /* 40 */

    printf("Linked-list now:  ");
    list_display();                   /* 30 20 */


    return 0;
}
