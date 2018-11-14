#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
#define MAX 5
int top=-1;
void push(int a[],int item)
{
    char c;
    if(top==MAX-1)
    {
        cout<<"Overflow";
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
    int element=0;
    if(top==-1)
    {
        cout<<"Underflow";
    }
    else{
        element=a[top];
        cout<<element<<"\n";
        top--;
    }
}
void traverse(int a[])
{
    int i;
if(top==-1)
{
    cout<<"Stack is empty";
}
else
{
    for(i=0;i<=top;i++)
        cout<<a[i]<<" ";
}
}
int main()
{
    int a[MAX],ch,item;
    while(1)
    {
        cout<<"Press 1 to insert item in stack\n";
        cout<<"Press 2 to delete item in stack\n";
        cout<<"Press 3 to display\n";
        cout<<"Press 4 to exit\n";
        cout<<"Enter your choice\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter the item to insert";
            cin>>item;
            push(a,item);
            break;
        case 2:
            pop(a);
            traverse(a);
            getch();
            break;
        case 3:
            traverse(a);
            getch();
            break;
        case 4:
            exit(0);
        }
        system("CLS");
    }
}
