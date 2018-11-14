#include<iostream>
#include<stdlib.h>
using namespace std;
class list
{
    public:
    int info;
    list * next;
};
class linkedlist:public list
{
private:
    list * start;
public:
    linkedlist()
    {
        start=NULL;
    }
    void insatbeg(int);
    void insatend(int);
    void delatbeg();
    void delatend();
    void displist();
    void revlist();
};
void linkedlist::insatbeg(int item)
{
    list *ptr,*temp;
    ptr=new list;
    if(start==NULL)
    {
        ptr->info=item;
        ptr->next=ptr;
        start=ptr;
    }
    else
    {
        ptr->info=item;
        ptr->next=start;
        temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        start=ptr;
    }
}
void linkedlist::insatend(int item)
{
     list *ptr;
    list *temp;
    ptr=new list;
    if(start==NULL)
    {
        ptr->info=item;
        ptr->next=ptr;
        start=ptr;
    }
    else
    {
         ptr->info=item;
        temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=start;
    }
}
void linkedlist::displist()
{
  list *temp;
 if(start==NULL)
 {
    cout<<"List is Empty";
 }
 else
{
    cout<<"LIST: ";
     for(temp=start;temp->next!=start;temp=temp->next)
     {
         cout<<temp->info<<" ";
     }
     cout<<temp->info;
 }
 cout<<"\n";
}
void linkedlist::delatbeg()
{
     list* temp;
    if(start==NULL)
    {
        cout<<"Underflow\n";
    }
    else if(start->next==start)
    {
        temp=start;
        start=NULL;
        delete temp;
    }
    else
    {
        temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=start->next;
        temp=start;
        start=temp->next;
        delete temp;
    }
}
void linkedlist::delatend()
{
     list* temp,*temp1;
    if(start==NULL)
    {
        cout<<"Underflow\n";
    }
    else if(start->next==start)
    {
        temp=start;
        start=NULL;
        delete temp;
    }
    else
    {
        temp=start;
        while(temp->next!=start)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=start;
        delete temp;
    }
}
void linkedlist::revlist()
{
     list *temp,*next,*prev;
    if(start==NULL)
    {
            cout<<"No node\n";
    }
    else if(start->next==start)
    {
      cout<<"Only one node, result is same\n";
    }
    else
    {
        prev=NULL;
        temp=start;
        next=NULL;
        while(temp->next!=NULL)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        temp->next=prev;
        start=prev;
    }
}
int main()
{
        linkedlist obj;
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
                obj.insatbeg(item);
                break;
            case 2:
                cout<<"Enter item to insert\n";
                cin>>item;
                obj.insatend(item);
                break;
            case 3:
                obj.delatbeg();
                obj.displist();
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 4:
                obj.delatend();
                obj.displist();
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 5:
                obj.displist();
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 6:
               obj.revlist();
                obj.displist();
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            default:
                obj.displist();
                exit(0);
            }
            system("CLS");
            }
}
