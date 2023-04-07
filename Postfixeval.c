#include <stdio.h>
#include <stdlib.h>
#define MS 5
char infix[50], postfix[50], item;
void convert();
struct stack
{
    int top;
    char item[MS];
} s;
void push(char value)
{
    if (s.top == (MS - 1))
    {
        printf("The stack is overflow\n");
        exit(0);
    }
    else
    {
        s.item[++s.top] = value;
    }
}
int pop()
{
    if (s.top == -1)
    {
        printf("stack underflow\n");
        exit(0);
    }
    else
        return (s.item[s.top--]);
}

int operation(int a, int b, char c)
{
    switch (c)
    {
    case '^':
        return (pow(a, b));
    case '*':
        return (a * b);
    case '%':
        return (a % b);
    case '/':
        return (a / b);
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    }
}
int evaluate()
{
    int i, a, b, ans, value;
    char symb;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        symb = postfix[i];
        if ((symb >= '0') && (symb <= '9'))
        {
            push((int)(symb - '0'));
        }
        else
        {
            a = pop();
            b = pop();
            value = operation(b, a, symb);
            push(value);
        }
    }
    ans = pop();
    return ans;
}
void main()
{
    s.top = -1;
    int ans;
    printf("Enter the postfix expression\n");
    gets(postfix);
    ans = evaluate();
    printf("The resultant ans is %d\n", ans);
}