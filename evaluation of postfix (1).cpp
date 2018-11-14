#include<iostream>
#include<string.h>
#include<string>
using namespace std;
#define MAX 100
int top=-1;
void push(int a[], int item)
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
void pop(int a[])
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
int evaluate(int a,int b,char opr)
{
    if(opr=='+')
        return b+a;
    else if(opr=='-')
        return b-a;
    else if(opr=='*')
        return b*a;
    else if(opr=='/')
        return b/a;
    else
        return b^a;
}
int main()
{
        char str[100];
        int len,prec,operand[100],i,k=0,j=0;
        cout<<"Enter the postfix expression\n";
        cin>>str;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]>='0'&&str[i]<='9')
               push(operand,str[i]-'0');
            else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
            {
               prec=evaluate(operand[top],operand[top-1],str[i]);
               pop(operand);
               pop(operand);
               push(operand,prec);
            }

        }
        cout<<operand[top];
}
