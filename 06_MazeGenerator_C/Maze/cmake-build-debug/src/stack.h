#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

void push(struct Node **top, struct point x);
int isEmpty(struct Node* top);
struct point peek(struct Node *top);
struct point pop(struct Node** top);
int stackSize();

#endif //STACK_H