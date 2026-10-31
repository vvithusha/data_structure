#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node* buildChain(int n) {
    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  
        } else {
            tail->next = newNode; 
        }
        tail = newNode;  
    }
    return head;
}


int countNodes(struct Node *head) {
    int count = 0;
    struct Node *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


int sumChain(struct Node *head) {
    int sum = 0;
    struct Node *current = head;

    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}


void printChain(struct Node *head) {
    struct Node *current = head;
    printf("Chain: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


void freeChain(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = buildChain(n);

    printChain(head);
    printf("Number of nodes: %d\n", countNodes(head));
    printf("Sum of data values: %d\n", sumChain(head));

    freeChain(head);
    return 0;
}