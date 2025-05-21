#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"

// Function to create a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        perror("Failed to allocate memory for queue");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = capacity - 1; // Initialize rear for circular queue behavior
    queue->size = 0;
    queue->items = (int*)malloc(queue->capacity * sizeof(int));
    if (!queue->items) {
        perror("Failed to allocate memory for queue items");
        free(queue);
        exit(EXIT_FAILURE);
    }
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->items[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Return -1 or some indicator of error
    }
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to free the memory allocated for the queue
void freeQueue(struct Queue* queue) {
    if (queue) {
        if (queue->items) {
            free(queue->items);
        }
        free(queue);
    }
}

// Function to perform Breadth First Search
void bfs(int numVertices, int** adjMatrix, int startVertex) {
    if (startVertex < 0 || startVertex >= numVertices) {
        printf("Invalid start vertex\n");
        return;
    }

    // Dynamically allocate visited array
    int* visited = (int*)malloc(numVertices * sizeof(int));
    if (!visited) {
        perror("Failed to allocate memory for visited array");
        return;
    }
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = 0; // 0 for false, 1 for true
    }

    // Create a queue
    struct Queue* q = createQueue(numVertices);
    if (!q) {
        free(visited);
        // createQueue already prints an error
        return;
    }

    // Mark startVertex as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS Traversal starting from vertex %d:\n", startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n"); // Newline after traversal

    // Free the queue and visited array
    freeQueue(q);
    free(visited);
}

int main() {
    int numVertices = 5;

    // Define the adjacency matrix
    int graph[5][5] = {
        {0, 1, 1, 0, 0},  // Node 0 is connected to 1, 2
        {1, 0, 0, 1, 0},  // Node 1 is connected to 0, 3
        {1, 0, 0, 1, 1},  // Node 2 is connected to 0, 3, 4
        {0, 1, 1, 0, 0},  // Node 3 is connected to 1, 2
        {0, 0, 1, 0, 0}   // Node 4 is connected to 2
    };

    // Create an int** to pass to the bfs function
    // Note: In C, VLA of pointers like this is fine for this context,
    // but for more general dynamic 2D arrays, malloc would be used for rows.
    int* adjMatrixToSend[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjMatrixToSend[i] = graph[i];
    }

    // Call the BFS function with different starting vertices
    printf("Testing BFS starting from vertex 0:\n");
    bfs(numVertices, adjMatrixToSend, 0);
    printf("\n"); // Add a newline for better separation of test outputs

    printf("Testing BFS starting from vertex 3:\n");
    bfs(numVertices, adjMatrixToSend, 3);
    printf("\n");

    printf("Testing BFS starting from vertex 4:\n");
    bfs(numVertices, adjMatrixToSend, 4);
    printf("\n");
    
    // Example of testing with an invalid start vertex
    printf("Testing BFS starting from an invalid vertex (e.g., 5 for a 0-4 indexed graph):\n");
    bfs(numVertices, adjMatrixToSend, 5); // Should print "Invalid start vertex"
    printf("\n");

    printf("Testing BFS starting from an invalid vertex (e.g., -1):\n");
    bfs(numVertices, adjMatrixToSend, -1); // Should print "Invalid start vertex"
    printf("\n");

    return 0;
}
