#include<iostream>
#include<stdlib.h>
using namespace std;
struct list
{
    int priority;
    int info;
    struct list * next;
};
struct list * front =NULL,*rear=NULL;
void insertqueue(int item,int pr)
{
    struct list * ptr,*q;
    ptr=new list;
    if(front==NULL||ptr->priority<=front->priority)
    {
        ptr->info=item;
        ptr->priority=pr;
        ptr->next=front;
        front=ptr;
    }
    else
    {
        ptr->info=item;
        ptr->priority=pr;
        q=front;
        while(q->next!=NULL&&ptr->priority>q->next->priority)
        {
            q=q->next;
        }
        ptr->next=q->next;
        q->next=ptr;
    }
}
void deletequeue()
{
    int p;
    if(front==NULL)
    {
        cout<<"Underflow\n";
    }
    else
    {
        p=front->info;
        cout<<p<<"\n";
        front=front->next;
    }
}
void traversequeue()
{
    struct list * temp;
    for(temp=front;temp->next!=NULL;temp=temp->next)
    {
    cout<<temp->info<<" ";
    }
    cout<<temp->info;
}
int main()
{
   int  i,ch,item,pr;
    char c;
    while(1)
    {
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Traverse\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter element and priority\n";
            cin>>item>>pr;
            insertqueue(item,pr);
            break;
        case 2:
           deletequeue();
            traversequeue();
             char c;
        cout<<"\nPress C to continue: ";
            cin>>c;
            break;
        case 3:
            traversequeue();
            cout<<"\nPress C to continue: ";
            cin>>c;
            break;
        case 4:
            traversequeue();
            exit(0);
        }
        system("CLS");
    }
}
