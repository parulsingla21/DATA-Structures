#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 5
int top=-1;
void push(int a[],int item)
{
    char c;
    if(top==MAX-1)
    {
        cout<<"Overflow\n";
        cout<<"Press c to continue ";
            cin>>c;
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
        cout<<"Deleted Element: "<<ele;
        top--;
        cout<<"\n";
    }
}
void traverse(int a[])
{
    if(top==-1)
        cout<<"Stack is empty\n";
    else
    {
    cout<<"Stack: ";
    for(int i=0;i<=top;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    }
}
int main()
{
    int a[MAX],ch,item;
    char c;
    while(1)
    {
        cout<<"Press 1 to insert item in stack\n";
        cout<<"Press 2 to delete item in stack\n";
        cout<<"Press 3 to display\n";
        cout<<"Press E to exit\n";
        cout<<"Enter your choice\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter element to be inserted\n";
            cin>>item;
            push(a,item);
            break;
        case 2:
            pop(a);
            traverse(a);
            cout<<"Press c to continue ";
            cin>>c;
            break;
        case 3:
            traverse(a);
            cout<<"Press c to continue ";
            cin>>c;
            break;
        default:
            traverse(a);
            exit(0);
        }
        system("CLS");
    }
}
