
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Insert a node in sorted order
struct Node* insertSorted(struct Node *head, int value) {

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    // Case 1: Empty list or insert at beginning
    if (head == NULL || value < head->data) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Case 2: Find correct position
    struct Node *temp = head;

    while (temp->next != NULL &&
           temp->next->data < value) {
        temp = temp->next;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Display linked list
void display(struct Node *head) {

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {

    struct Node *head = NULL;

    head = insertSorted(head, 30);
    head = insertSorted(head, 10);
    head = insertSorted(head, 40);
    head = insertSorted(head, 20);
    head = insertSorted(head, 50);

    printf("Sorted Linked List:\n");
    display(head);

    return 0;
}
