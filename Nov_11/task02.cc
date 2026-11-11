
#include <stdio.h>
#include <stdlib.h>

/* =========================================
   QUEUE STRUCTURE
   ========================================= */

struct queueArray {
    int *array;
    int capacity;
    int first;
    int length;
};

/* =========================================
   BASIC QUEUE OPERATIONS
   ========================================= */

// Create a new queue
struct queueArray* createQueue(int capacity) {

    struct queueArray *q =
        (struct queueArray*)malloc(sizeof(struct queueArray));

    if (q == NULL)
        return NULL;

    q->array = (int*)malloc(capacity * sizeof(int));

    if (q->array == NULL) {
        free(q);
        return NULL;
    }

    q->capacity = capacity;
    q->first = 0;
    q->length = 0;

    return q;
}

// Check whether queue is empty
int isEmpty(struct queueArray *q) {
    return q->length == 0;
}

// Check whether queue is full
int isFull(struct queueArray *q) {
    return q->length == q->capacity;
}

// Insert an element into the queue
int insert(struct queueArray *q, int value) {

    if (isFull(q)) {
        printf("Queue Overflow! Queue is full.\n");
        return 0;
    }

    // Calculate the rear position using circular indexing
    int rear = (q->first + q->length) % q->capacity;

    q->array[rear] = value;
    q->length++;

    return 1;
}

// Remove the front element from the queue
int removeFront(struct queueArray *q, int *removedValue) {

    if (isEmpty(q)) {
        printf("Queue Underflow! Queue is empty.\n");
        return 0;
    }

    *removedValue = q->array[q->first];

    // Move front to the next position
    q->first = (q->first + 1) % q->capacity;

    q->length--;

    return 1;
}

// Return the front element without removing it
int getFront(struct queueArray *q, int *value) {

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return 0;
    }

    *value = q->array[q->first];

    return 1;
}

// Display all queue elements
void displayQueue(struct queueArray *q) {

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    for (int i = 0; i < q->length; i++) {

        int index = (q->first + i) % q->capacity;

        printf("%d ", q->array[index]);
    }

    printf("\n");
}

// Display queue information
void displayInfo(struct queueArray *q) {

    int firstFree = (q->first + q->length) % q->capacity;

    printf("First     = %d\n", q->first);
    printf("FirstFree = %d\n", firstFree);
    printf("Length    = %d\n", q->length);
}

// Free allocated memory
void freeQueue(struct queueArray *q) {

    if (q != NULL) {
        free(q->array);
        free(q);
    }
}


/* =========================================
   QUESTION 5
   Find the sum of all queue elements
   ========================================= */

int sumQueue(struct queueArray *q) {

    int sum = 0;

    for (int i = 0; i < q->length; i++) {

        int index = (q->first + i) % q->capacity;

        sum = sum + q->array[index];
    }

    return sum;
}


/* =========================================
   QUESTION 6
   Find the maximum element in the queue
   ========================================= */

int maxQueue(struct queueArray *q, int *maximum) {

    if (isEmpty(q)) {
        printf("Queue is empty. No maximum value.\n");
        return 0;
    }

    // Initially, assume the first element is maximum
    *maximum = q->array[q->first];

    for (int i = 1; i < q->length; i++) {

        int index = (q->first + i) % q->capacity;

        if (q->array[index] > *maximum) {
            *maximum = q->array[index];
        }
    }

    return 1;
}


/* =========================================
   QUESTION 7
   Create a completely independent queue copy
   ========================================= */

struct queueArray* copyQueue(struct queueArray *q) {

    // Create another queue with the same capacity
    struct queueArray *newQueue = createQueue(q->capacity);

    if (newQueue == NULL)
        return NULL;

    // Copy the front position and length
    newQueue->first = q->first;
    newQueue->length = q->length;

    // Copy every array element
    for (int i = 0; i < q->capacity; i++) {

        newQueue->array[i] = q->array[i];
    }

    // Return the independent copy
    return newQueue;
}


/* =========================================
   QUESTION 8
   Rotate queue by moving front to rear

   Example:
   Before: 10 20 30
   After : 20 30 10

   Uses removeFront() and insert()
   ========================================= */

void rotateQueue(struct queueArray *q) {

    if (isEmpty(q)) {
        printf("Cannot rotate an empty queue.\n");
        return;
    }

    int value;

    // Remove the front element
    if (removeFront(q, &value)) {

        // Insert the removed element at the rear
        insert(q, value);
    }
}


/* =========================================
   MAIN FUNCTION
   Demonstrate QUESTIONS 1 - 8
   ========================================= */

int main() {

    int value;

    /* -------------------------------------
       QUESTION 1
       Insert 10, 20, 30, 40, 50
       Remove and print all elements
       ------------------------------------- */

    printf("\n========== QUESTION 1 ==========\n");

    struct queueArray *q1 = createQueue(5);

    insert(q1, 10);
    insert(q1, 20);
    insert(q1, 30);
    insert(q1, 40);
    insert(q1, 50);

    displayQueue(q1);

    printf("Removing elements:\n");

    while (!isEmpty(q1)) {

        removeFront(q1, &value);

        printf("%d ", value);
    }

    printf("\n");

    freeQueue(q1);


    /* -------------------------------------
       QUESTION 2
       Call getFront() twice
       Check whether length changes
       ------------------------------------- */

    printf("\n========== QUESTION 2 ==========\n");

    struct queueArray *q2 = createQueue(5);

    insert(q2, 10);
    insert(q2, 20);
    insert(q2, 30);

    int oldLength = q2->length;

    getFront(q2, &value);
    printf("First getFront() = %d\n", value);

    getFront(q2, &value);
    printf("Second getFront() = %d\n", value);

    printf("Original length = %d\n", oldLength);
    printf("Current length  = %d\n", q2->length);

    if (oldLength == q2->length) {
        printf("Length unchanged. getFront() does not remove elements.\n");
    }

    displayQueue(q2);

    freeQueue(q2);


    /* -------------------------------------
       QUESTION 3
       Queue capacity = 2
       Insert 3 elements (overflow)
       Remove 3 elements (underflow)
       ------------------------------------- */

    printf("\n========== QUESTION 3 ==========\n");

    struct queueArray *q3 = createQueue(2);

    insert(q3, 10);
    insert(q3, 20);

    // Third insertion causes overflow
    insert(q3, 30);

    displayQueue(q3);

    // Remove existing elements
    removeFront(q3, &value);
    printf("Removed: %d\n", value);

    removeFront(q3, &value);
    printf("Removed: %d\n", value);

    // Third removal causes underflow
    removeFront(q3, &value);

    freeQueue(q3);


    /* -------------------------------------
       QUESTION 4
       Capacity = 4
       Insert 4 elements
       Remove 2 elements
       Insert 2 more elements
       Check circular wrapping
       ------------------------------------- */

    printf("\n========== QUESTION 4 ==========\n");

    struct queueArray *q4 = createQueue(4);

    insert(q4, 10);
    insert(q4, 20);
    insert(q4, 30);
    insert(q4, 40);

    printf("After inserting 4 elements:\n");
    displayQueue(q4);

    // Remove two elements
    removeFront(q4, &value);
    printf("Removed: %d\n", value);

    removeFront(q4, &value);
    printf("Removed: %d\n", value);

    // Insert two more elements
    insert(q4, 50);
    insert(q4, 60);

    printf("After inserting 2 more elements:\n");
    displayQueue(q4);

    // Display first, firstFree and length
    displayInfo(q4);

    freeQueue(q4);


    /* -------------------------------------
       QUESTION 5
       Calculate the sum of queue elements
       ------------------------------------- */

    printf("\n========== QUESTION 5 ==========\n");

    struct queueArray *q5 = createQueue(5);

    insert(q5, 10);
    insert(q5, 20);
    insert(q5, 30);
    insert(q5, 40);
    insert(q5, 50);

    displayQueue(q5);

    printf("Sum of queue elements = %d\n", sumQueue(q5));

    freeQueue(q5);


    /* -------------------------------------
       QUESTION 6
       Find the maximum queue element
       ------------------------------------- */

    printf("\n========== QUESTION 6 ==========\n");

    struct queueArray *q6 = createQueue(5);

    insert(q6, 15);
    insert(q6, 40);
    insert(q6, 25);
    insert(q6, 80);
    insert(q6, 10);

    displayQueue(q6);

    if (maxQueue(q6, &value)) {
        printf("Maximum element = %d\n", value);
    }

    freeQueue(q6);


    /* -------------------------------------
       QUESTION 7
       Create an independent queue copy
       Remove an element from the copy
       Original queue must remain unchanged
       ------------------------------------- */

    printf("\n========== QUESTION 7 ==========\n");

    struct queueArray *q7 = createQueue(5);

    insert(q7, 10);
    insert(q7, 20);
    insert(q7, 30);

    printf("Original queue:\n");
    displayQueue(q7);

    // Create a deep copy
    struct queueArray *copy = copyQueue(q7);

    printf("Copied queue:\n");
    displayQueue(copy);

    // Remove an element only from the copied queue
    removeFront(copy, &value);

    printf("Removed from copied queue = %d\n", value);

    printf("Original queue after removal:\n");
    displayQueue(q7);

    printf("Copied queue after removal:\n");
    displayQueue(copy);

    freeQueue(q7);
    freeQueue(copy);


    /* -------------------------------------
       QUESTION 8
       Rotate queue by one position
       Move front element to rear
       ------------------------------------- */

    printf("\n========== QUESTION 8 ==========\n");

    struct queueArray *q8 = createQueue(5);

    insert(q8, 10);
    insert(q8, 20);
    insert(q8, 30);

    printf("Before rotation:\n");
    displayQueue(q8);

    rotateQueue(q8);

    printf("After rotation:\n");
    displayQueue(q8);

    freeQueue(q8);


    return 0;
}
