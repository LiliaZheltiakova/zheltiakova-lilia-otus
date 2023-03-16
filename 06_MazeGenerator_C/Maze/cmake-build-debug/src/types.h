#ifndef UNTITLED_TYPES_H
#define UNTITLED_TYPES_H

typedef struct point
{
    int y;
    int x;
}point;

typedef struct pointsArr
{
    point *points;
    int size;
}pointsArr;

struct Node
{
    struct point data;
    struct Node* next;
};

#endif //UNTITLED_TYPES_H
