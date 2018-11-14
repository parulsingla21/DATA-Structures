#include<iostream>
#include<stdlib.h>
using namespace std;
struct list
{
    int info;
    struct list * next;
};
 struct list * start=NULL;
void insatbeg(int item)
{
     struct list *ptr;
    ptr=new list;
    if(start==NULL)
    {
        ptr->info=item;
        ptr->next=NULL;
        start=ptr;
    }
    else
    {
        ptr->info=item;
        ptr->next=start;
        start=ptr;
    }
}
void insatend(int item)
{
     struct list *ptr;
     struct list *temp;
    ptr=new list;
    if(start==NULL)
    {
        ptr->info=item;
        ptr->next=NULL;
        start=ptr;
    }
    else
    {
        ptr->info=item;
        ptr->next=NULL;
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }
}
void displist()
{
  struct list *temp;
 if(start==NULL)
 {
    cout<<"List is Empty";
 }
 else
{
    cout<<"LIST: ";
     for(temp=start;temp!=NULL;temp=temp->next)
     {
         cout<<temp->info<<" ";
     }
 }
 cout<<"\n";
}
void delatbeg()
{
     struct list* temp;
    if(start==NULL)
    {
        cout<<"Underflow\n";
    }
    else
    {
        temp=start;
        start=temp->next;
        delete temp;
    }
}
void delatend()
{
     struct list* temp,*temp1;
    if(start==NULL)
    {
        cout<<"Underflow\n";
    }
    else if(start->next==NULL)
    {
        temp=start;
        start=NULL;
        delete temp;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        delete temp;
    }
}
void revlist()
{
     struct list *temp,*next,*prev;
    if(start==NULL)
    {
            cout<<"No node\n";
    }
    else if(start->next==NULL)
    {
      cout<<"Only one node, result is same\n";
    }
    else
    {
        prev=NULL;
        temp=start;
        next=NULL;
        while(temp!=NULL)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        start=prev;
    }
}
int main()
{
        int n,item,i;
        int ch;
        char c;
        while(1)
        {
            cout<<"Press 1 to insert item at the beginning\n";
            cout<<"Press 2 to insert item at the end\n";
            cout<<"Press 3 to delete item from the beginning\n";
            cout<<"Press 4 to delete item from the end\n";
            cout<<"Press 5 to display list\n";
            cout<<"Press 6 to reverse list\n";
            cout<<"Press E to exit\n";
            cout<<"Enter your choice: ";
            cin>>ch;
            switch(ch)
            {
            case 1:
                cout<<"Enter item to insert\n";
                cin>>item;
                insatbeg(item);
                break;
            case 2:
                cout<<"Enter item to insert\n";
                cin>>item;
                insatend(item);
                break;
            case 3:
                delatbeg();
                displist();
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 4:
                delatend();
                displist();
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 5:
                displist();
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 6:
                revlist();
                displist();
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            default:
                displist();
                exit(0);
            }
            system("CLS");
            }

}
