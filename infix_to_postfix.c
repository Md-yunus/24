#include<stdio.h>
#include<ctype.h>
#define size 100
char stack[size];
int top=-1;
void push(char );
int pop();
int prior(char );
int main()
{
    char a[100];
    char ch;
    fgets(a,sizeof(a),stdin);
    for(int i=0;a[i]!='\0';i++)
    {
        if(isalnum(a[i]))
            printf("%c",a[i]);
        else if(a[i]=='(')
            push(a[i]);
        else if(a[i]==')')
        {
            while((ch=pop())!='(')
            {
                printf("%c",ch);
            }
            
        }
        else {
        while (prior(stack[top])>=prior(a[i]))
        {
            printf("%c",pop());
        }
        push(a[i]);
        }
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
    
}
int prior(char a)
{
    if(a=='+' || a=='-')
        return 1;
    else if(a=='*' || a=='/')
        return 2;
    else if(a=='^')
        return 3;
    else if(a=='(')
        return 0;
}
void push(char a)
{
    top++;
    stack[top]=a;
}
int pop()
{
    return stack[top--];
}
