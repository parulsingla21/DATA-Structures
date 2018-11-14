#include<iostream>
#include<stdlib.h>
using namespace std;
struct list
{
    int info;
    struct list * next;
};
struct list * front =NULL,*rear=NULL;
void insertqueue(int item)
{
    struct list * ptr;
    ptr=new list;
    if(front==NULL)
    {
        ptr->info=item;
        ptr->next=NULL;
        front=ptr;
        rear=ptr;
    }
    else
    {
        ptr->info=item;
        ptr->next=NULL;
        rear->next=ptr;
        rear=ptr;
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
    for(temp=front;temp!=NULL;temp=temp->next)
    {
    cout<<temp->info<<" ";
    }
}
int main()
{
   int  i,ch,item;
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
            cout<<"Enter element\n";
            cin>>item;
            insertqueue(item);
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
