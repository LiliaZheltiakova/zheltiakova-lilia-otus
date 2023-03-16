#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"
#include "types.h"

void DynamicArrayPrint(char**, int);
void removeWall(struct point*, struct point*, char **, int);
struct pointsArr *getNeighbours(struct point*, char**, int);
int randomRange(int, int);

// Legend
char pointInt = 'o';
char visitedPoint = '.';
char wall = '#';

struct Node *stack = NULL;

int main()
{
    int size = 0;
    do
    {
        printf("Input maze size (at least 3).\n");
        scanf("%d", &size);
    } while(size <= 3);
    size = size * 2 + 1;

    char **p_cell = malloc(sizeof(char*) * size * 3);
    for(int i = 0; i < size; i++)
    {
        p_cell[i] = malloc(sizeof(char) * size * 3);
    }

    // Matrix init
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if((i % 2 != 0 && j % 2 != 0) && ( i < size - 1 && j < size - 1))
            {
                p_cell[i][j] = pointInt;
            }
            else p_cell[i][j] = wall;
        }
    }

    // Maze generation
    struct point startPoint = {size - 4, 1};
    struct point currentPoint = startPoint;
    struct point neighbourPoint;

    int randomNumber;
    int unvisitedPoints = 0;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(p_cell[i][j] == pointInt)
                unvisitedPoints++;
        }
    }

    p_cell[currentPoint.y][currentPoint.x] = visitedPoint;

    do {
        struct pointsArr *neighbourPoints = getNeighbours(&currentPoint, p_cell, size);
        if(neighbourPoints->size != 0)
        {
            randomNumber = randomRange(0, neighbourPoints->size - 1);
            neighbourPoint = neighbourPoints->points[randomNumber];

            push(&stack, currentPoint);

            removeWall(&currentPoint, &neighbourPoint, p_cell, size);

            currentPoint = neighbourPoint;
            if(currentPoint.y > 0 && currentPoint.y < size && currentPoint.x > 0 && currentPoint.x < size)
            {
                p_cell[currentPoint.y][currentPoint.x] = visitedPoint;
                unvisitedPoints--;
                DynamicArrayPrint(p_cell, size);
                printf("\n");
            }
        }

        else if(stackSize() > 0)
        {
            currentPoint = pop(&stack);
        }

        else
        {
            unvisitedPoints = 0;
        }

        free(neighbourPoints->points);
        free(neighbourPoints);
    } while (unvisitedPoints > 0);

    for(int i = 0; i < size; i++)
    {
        free(p_cell[i]);
    }
    free(p_cell);

    return 0;
}

void DynamicArrayPrint(char **arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

void removeWall(struct point *currentPoint, struct point *neighbourPoint, char **maze, int mazeSize)
{
    int yDiff = currentPoint->y - neighbourPoint->y;
    int xDiff = currentPoint->x - neighbourPoint->x;
    int yAdd, xAdd;
    point target;

    if(yDiff != 0)
    {
        yAdd = yDiff / abs(yDiff);
    }

    else yAdd = 0;

    if(xDiff != 0)
    {
        xAdd = xDiff / abs(xDiff);
    }

    else xAdd = 0;

    target.y = currentPoint->y - yAdd;
    target.x = currentPoint->x - xAdd;

    if(target.y > 0 && target.y < mazeSize && target.x > 0 && target.x < mazeSize)
        maze[target.y][target.x] = visitedPoint;
}

struct pointsArr *getNeighbours(point *currentPoint, char **maze, int mazeSize)
{
    //up 0
    point up = {currentPoint->y - 2, currentPoint->x};
    //down 1
    point down = {currentPoint->y + 2, currentPoint->x};
    //left 2
    point left = {currentPoint->y, currentPoint->x - 2};
    //right 3
    point right = {currentPoint->y, currentPoint->x + 2};

    point nPoints[4] = {up, down, left, right};

    struct pointsArr *neighbourPoints;
    int nSize = 0;
    neighbourPoints = malloc(4 * sizeof(struct pointsArr));
    neighbourPoints->points = malloc(4 * sizeof(struct point));
    neighbourPoints->size = 0;

    for(int i = 0; i < 4; i++)
    {
        if(nPoints[i].y > 0 && nPoints[i].y < mazeSize && nPoints[i].x > 0 && nPoints[i].x < mazeSize)
        {
            if(maze[nPoints[i].y][nPoints[i].x] != '#' && maze[nPoints[i].y][nPoints[i].x] != '.')
            {
                neighbourPoints->points[nSize] = nPoints[i];
                nSize++;
            }
        }
    }
    neighbourPoints->size = nSize;
    return neighbourPoints;
}

int randomRange(int floor, int ceiling)
{
    srand(time(0));
    return rand() % (ceiling - floor + 1) + floor;
}