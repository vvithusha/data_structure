#include <stdio.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char symbol)
{
    if(top < MAX-1)
    {
        stack[++top] = symbol;
    }
}

char pop()
{
    if(top >= 0)
    {
        return stack[top--];
    }
    return '\0';
}

bool ismatching(char open, char close)
{
    return (open=='(' && close==')') ||
           (open=='{' && close=='}') ||
           (open=='[' && close==']');
}

bool checksymbol(char str[])
{
    top = -1;
    for(int i = 0; str[i] != '\0'; i++)
    {
        char symbol = str[i];

        if(symbol == '(' || symbol == '[' || symbol == '{')
        {
            push(symbol);
        }
        else if(symbol == ')' || symbol == '}' || symbol == ']')
        {
            if(top == -1)
            {
                return false;
            }
            char open = pop();
            if(!ismatching(open, symbol))   // ! சேர்க்கப்பட்டது
            {
                return false;
            }
        }
    }
    return top == -1;
}

int main()
{
    char str[MAX];
    printf("Enter a sequence of symbol:");
    scanf("%99s", str);   // buffer overflow தவிர்க்க

    if(checksymbol(str))
    {
        printf("Legal sequence\n");
    }
    else
    {
        printf("ERROR: Illegal Sequence\n");
    }
    return 0;
}