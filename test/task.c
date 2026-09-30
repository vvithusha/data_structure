#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* operation(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;     
        current->next = prev;     
        prev = current;           
        current = next;           
    }
    return prev;                  
}


struct Node* newNode(int data) {
    struct Node* node = 
    (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}


void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);

    printf("Original: ");
    printList(head);

    head = operation(head);

    printf("Reversed: ");
    printList(head);

    return 0;
}