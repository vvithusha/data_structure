#include <stdio.h>
#include <stdlib.h>
struct array_stack
{
    int *array;
    int capacity;
    int top;
};

void intitArrayStack(struct array_stack *s , int cap)
{
     s->capacity = cap;
     s->top = -1;
     s->array = (int *)malloc(s->capacity * sizeof(int));
}

bool isempty(struct array_stack *s)
{
    return s->top == -1;
}

bool isfull(struct array_stack *s)
{
    return s->top == s->capacity - 1;
}

void push(struct array_stack *s , int value)
{
    if(isfull(s))
    {
        printf("Stack is Full\n");
    }
    else
    {
        s->top++;
        s->array[s->top]=value;
    }
}

int pop(struct array_stack *s)
{
    if(isempty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    else
    {
        int value = s->array[s->top];
        s->top--;
        return value;
    }
}
int peek(struct array_stack *s)
{
    if(isempty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    else
    {
        return s->array[s->top];
    }
}
void freearraystack(struct array_stack *s)
{
    free(s->array);    
    s->array = NULL;   
    s->top = -1;
    s->capacity = 0;
}
int isBalanced(char expr[])
{
    struct array_stack s;
    intitArrayStack(&s, 100);

    for (int i = 0; expr[i] != '\0'; i++)
    {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(&s, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isempty(&s))
            {
                freearraystack(&s);
                return 0;
            }
            char top = pop(&s);          
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                freearraystack(&s);
                return 0;
            }
        }
    }
    int result = isempty(&s);
    freearraystack(&s);
    return result;
}

int main()
{
    struct array_stack s;
    printf("Array Stack intitialized\n");
    intitArrayStack(&s, 10);
    printf("Array Stack capacity: %d\n", s.capacity);
    printf("Array Stack top index: %d\n", s.top);

    printf("Is the stack Empty? %s\n", isempty(&s) ? "yes" : "no");
    printf("IS the Stack FUll ? %s\n", isfull(&s) ? "yes" : "no");

    push(&s, 5);
    push(&s, 10);
    push(&s, 15);
    printf("After pushing 3 elements:\n");
    for(int i=0 ; i<=s.top ; i++)
    {
        printf("%d elemet in the stack is: %d\n", i , s.array[i]);
    }
    pop(&s);
    printf("After popping 1 element:\n");
    for(int i=0 ; i<=s.top ; i++)
    {
        printf("%d elemet in the stack is: %d\n", i , s.array[i]);
    }

    printf("Top element in the stack is: %d\n", peek(&s));

    isBalanced("({[]})") ? printf("({[]}) : Balanced\n") : printf("({[]}) :Not Balanced\n");
    isBalanced("({[}])") ? printf("({[}]) : Balanced\n") : printf("({[}]) :Not Balanced\n");
    
    return 0;

}




