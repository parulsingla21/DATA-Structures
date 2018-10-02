#include<iostream>
#include<stdlib.h>
using namespace std;
class linkedlist
{
private:
     struct list
{
    int info;
    struct list * next,*prev;
};
struct list * start,*end;
public:
    linkedlist()
    {
        start=NULL;
        end=NULL;
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
     struct list *ptr;
    ptr=new list;
    if(start==NULL)
    {
        ptr->info=item;
        start=ptr;
        end=ptr;
        ptr->next=NULL;
        ptr->prev=NULL;
    }
    else
    {
        ptr->info=item;
        ptr->next=start;
        start->prev=ptr;
        start=ptr;
        start->prev=NULL;
    }
}
void linkedlist::insatend(int item)
{
     struct list *ptr;
    ptr=new list;
    if(end==NULL)
    {
        ptr->info=item;
        ptr->next=NULL;
        ptr->prev=NULL;
        start=ptr;
        end=ptr;
    }
    else
    {
        ptr->info=item;
        end->next=ptr;
        ptr->next=NULL;
        ptr->prev=end;
        end=ptr;
    }
}
void linkedlist::displist()
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
void linkedlist::delatbeg()
{
     struct list* temp;
    if(start==NULL)
    {
        cout<<"Underflow\n";
    }
    else if(start==end)
    {
        temp=start;
        start=NULL;
        end=NULL;
        delete temp;
    }
    else
    {
        temp=start;
        start=temp->next;
        start->prev=NULL;
        delete temp;
    }
}
void linkedlist::delatend()
{
     struct list* temp;
    if(start==NULL)
    {
        cout<<"Underflow\n";
    }
    else if(start==end)
    {
        temp=start;
        start=NULL;
        end=NULL;
        delete temp;
    }
    else
    {
        temp=end;
        end=temp->prev;
        end->next=NULL;
        delete temp;
    }
}
void linkedlist::revlist()
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
