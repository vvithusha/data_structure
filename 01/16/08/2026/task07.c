#include <stdio.h>
#include <stdlib.h>

// ---------------- Struct Definition ----------------
struct arraybaselist
{
    int *data;
    int first;
    int firstfree;
    int maxsize;
    int length;
};

// ---------------- Append Function ----------------
void appendlist(int newdata, struct arraybaselist *l)
{
    if (l->length == l->maxsize)
    {
        printf("Error : list is full\n");
        return;
    }

    l->data[l->firstfree++] = newdata;
    l->length++;

    if (l->first == -1)
    {
        l->first = 0;
    }
}

// ---------------- Insert at Index Function ----------------
void insertAtIndex(struct arraybaselist *l, int index, int newdata)
{
    if (l->length == l->maxsize)
    {
        printf("Error : list is full\n");
        return;
    }

    if (index < 0 || index > l->length)
    {
        printf("Error : invalid index\n");
        return;
    }

    for (int i = l->length; i > index; i--)
    {
        l->data[i] = l->data[i - 1];
    }

    l->data[index] = newdata;
    l->length++;
    l->firstfree++;

    if (l->first == -1)
    {
        l->first = 0;
    }
}

// ---------------- Delete at Index Function ----------------
void deleteAtIndex(struct arraybaselist *l, int index)
{
    if (l->length == 0)
    {
        printf("Error : list is empty\n");
        return;
    }

    if (index < 0 || index >= l->length)
    {
        printf("Error : invalid index\n");
        return;
    }

    for (int i = index; i < l->length - 1; i++)
    {
        l->data[i] = l->data[i + 1];
    }

    l->length--;
    l->firstfree--;

    if (l->length == 0)
    {
        l->first = -1;
    }
}

// ---------------- Search Function ----------------
int searchElement(struct arraybaselist *l, int key)
{
    for (int i = 0; i < l->length; i++)
    {
        if (l->data[i] == key)
        {
            return i;   // found — index return pannuрадhu
        }
    }
    return -1;   // not found
}

// ---------------- Display Function ----------------
void printList(struct arraybaselist *l)
{
    if (l->length == 0)
    {
        printf("List is empty\n");
        return;
    }

    printf("List : ");
    for (int i = 0; i < l->length; i++)
    {
        printf("%d ", l->data[i]);
    }
    printf("\n");
}

// ---------------- Main Function ----------------
int main()
{
    struct arraybaselist mylist;

    // Initialize the list
    mylist.data = (int *) malloc(10 * sizeof(int));
    mylist.first = -1;
    mylist.firstfree = 0;
    mylist.maxsize = 10;
    mylist.length = 0;

    // ---- Append elements ----
    appendlist(10, &mylist);
    appendlist(20, &mylist);
    appendlist(30, &mylist);
    appendlist(40, &mylist);

    printf("After append:\n");
    printList(&mylist);

    // ---- Insert at index ----
    insertAtIndex(&mylist, 2, 99);
    printf("\nAfter insert 99 at index 2:\n");
    printList(&mylist);

    // ---- Search ----
    int pos = searchElement(&mylist, 99);
    if (pos != -1)
        printf("\n99 found at index %d\n", pos);
    else
        printf("\n99 not found\n");

    // ---- Delete at index ----
    deleteAtIndex(&mylist, 1);
    printf("\nAfter delete at index 1:\n");
    printList(&mylist);

    // ---- Free allocated memory ----
    free(mylist.data);

    return 0;
}