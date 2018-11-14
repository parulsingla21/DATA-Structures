#include<iostream>
#include<stdlib.h>
using namespace std;
struct stack
{
    int info;
    struct stack *next;
};
struct stack * top=NULL;
void push(int item)
{
    struct stack * ptr;
    ptr=new stack;
    if(top==NULL)
    {
        ptr->info=item;
        ptr->next=NULL;
        top=ptr;
    }
    else
    {
        ptr->info=item;
        ptr->next=top;
        top=ptr;
    }
}
void pop()
{
     struct stack * temp;
    if(top==NULL)
    {
        cout<<"Underflow\n";
    }
    else
    {
       temp=top;
       top=top->next;
       cout<<"Element to be deleted: "<<temp->info<<"\n";
       delete temp;
    }
}
void traverse()
{
     struct stack * temp;
    if (top==NULL)
        cout<<"Underflow\n";
    else
    {
        cout<<"Stack: ";
        for(temp=top;temp!=NULL;temp=temp->next)
            cout<<temp->info<<" ";
        cout<<"\n";
    }

}
int main()
{
    int ch,item;
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
            push(item);
            break;
        case 2:
            pop();
            traverse();
            cout<<"Press c to continue ";
            cin>>c;
            break;
        case 3:
            traverse();
            cout<<"Press c to continue ";
            cin>>c;
            break;
        default:
            traverse();
            exit(0);
        }
        system("CLS");
    }
}
