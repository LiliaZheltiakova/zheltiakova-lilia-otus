#include "stack.h"

int nodesCount;

void push(struct Node **top, struct point x)
{
    struct Node* node = NULL;
    node = (struct Node*)malloc(sizeof(struct Node));

    if (!node)
    {
        printf("Heap Overflow\n");
        exit(-1);
    }

    node->data = x;
    node->next = *top;
    *top = node;
    nodesCount += 1;
}

int isEmpty(struct Node* top)
{
    return top == NULL;
}

struct point peek(struct Node *top)
{
    if (!isEmpty(top)) {
        return top->data;
    }
    else {
        printf("The stack is empty\n");
        exit(EXIT_FAILURE);
    }
}

struct point pop(struct Node** top)
{
    struct Node *node;
    if (*top == NULL)
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }

    struct point x = peek(*top);
    node = *top;
    *top = (*top)->next;
    nodesCount -= 1;
    free(node);
    return x;
}

int stackSize()
{
    return nodesCount;
}