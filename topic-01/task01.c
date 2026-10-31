
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *next;
};

// Insert a node in ascending order
struct Node* insert(struct Node *head, int value) {

    struct Node *newNode;
    struct Node *temp;

    // Create a new node
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->key = value;
    newNode->next = NULL;

    // If list is empty or new key is smaller than first key
    if (head == NULL || value < head->key) {

        newNode->next = head;
        head = newNode;

        return head;
    }

    // Find the correct position
    temp = head;

    while (temp->next != NULL &&
           temp->next->key < value) {

        temp = temp->next;
    }

    // Insert the node
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Display the linked list
void display(struct Node *head) {

    struct Node *temp = head;

    while (temp != NULL) {

        printf("%d -> ", temp->key);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    struct Node *head = NULL;

    head = insert(head, 40);
    head = insert(head, 10);
    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 50);

    printf("Sorted Linked List:\n");

    display(head);

    return 0;
}
