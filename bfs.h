#ifndef BFS_H
#define BFS_H

// It's good practice to include headers needed for type definitions used in function signatures,
// like stdlib.h for size_t if it were used. For the current functions, no standard library
// headers are strictly needed in the .h file itself for the function signatures shown.

// Structure for the queue
struct Queue {
    int* items;
    int front;
    int rear;
    int capacity;
    int size; // Current number of items in the queue
};

// Queue management functions
struct Queue* createQueue(int capacity);
int isFull(struct Queue* queue);
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int item);
int dequeue(struct Queue* queue);
void freeQueue(struct Queue* queue);

// BFS algorithm function
// adjMatrix is a pointer to an array of integer pointers (representing a 2D array)
void bfs(int numVertices, int** adjMatrix, int startVertex);

#endif /* BFS_H */
