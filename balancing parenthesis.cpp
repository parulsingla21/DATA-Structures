#include<iostream>
#include<string.h>
using namespace std;
#define MAX 100
int top=-1;
void push(char a[],char item)
{
    if(top==MAX-1)
    {
        cout<<"Overflow\n";
    }
    else
    {
        top++;
        a[top]=item;
    }
}
void pop(char a[])
{
    int ele;
    if(top==-1)
        cout<<"Underflow\n";
    else
    {
        ele=a[top];
        top--;
    }
}

int main()
{
        char str[100],operand[100];
        int k=0,j=0,i;
        int len,prec,flag=0;
        cout<<"Enter the expression\n";
        cin>>str;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            flag=0;
            if(str[i]=='{'||str[i]=='['||str[i]=='(')
                push(operand,str[i]);
            else if(str[i]=='}')
            {
                if(top==-1)
                {
                    flag=1;
                    break;
                }
                else
                {
                    char ch=operand[top];
                    pop(operand);
                   if(ch!='{')
                    {
                        flag=1;
                        break;
                    }

                }
            }
            else if(str[i]==']')
            {
                if(top==-1)
                {
                    flag=1;
                    break;
                }
                else
                {
                     char ch=operand[top];
                    pop(operand);
                   if(ch!='[')
                    {
                        flag=1;
                        break;
                }
            }
            }
            else
            {
                if(top==-1)
                {
                    flag=1;
                    break;
                }
                else
                {
                    char ch=operand[top];
                    pop(operand);
                   if(ch!='(')
                    {
                        flag=1;
                        break;
                }
                }
            }
        }
        if(flag==1)
            cout<<"Unbalanced";
        else
        {
            if(top==-1)
                cout<<"Balanced";
            else
                cout<<"Unbalanced";
        }
}
