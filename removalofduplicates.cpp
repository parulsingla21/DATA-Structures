#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct list
{
    int rollno;
    char name[50];
    int age;
    struct list * next;
};
 struct list * start=NULL;
void insatend(int item,char name[50],int age)
{
     struct list *ptr;
     struct list *temp;
    ptr=new list;
    if(start==NULL)
    {
        ptr->rollno=item;
        strcpy(ptr->name,name);
        ptr->age=age;
        ptr->next=NULL;
        start=ptr;
    }
    else
    {
        ptr->rollno=item;
        strcpy(ptr->name,name);
        ptr->age=age;
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
    cout<<"LIST:\n";
     for(temp=start;temp!=NULL;temp=temp->next)
     {
         cout<<"Roll no: "<<temp->rollno<<"\t";
         cout<<"Name: "<<temp->name<<"\t";
         cout<<"Age: "<<temp->age<<"\n";
     }
}
}
void bubblesort()
{
    struct list *temp,*temp1;
    int var;
    char name[50];
    if(start==NULL)
        return;
    else
    {
        for(temp=start;temp->next!=NULL;temp=temp->next)
        {
             for(temp1=start;temp1->next!=NULL;temp1=temp1->next)
               {
                if(temp1->rollno>temp1->next->rollno)
                {
                    var=temp1->rollno;
                    temp1->rollno=temp1->next->rollno;
                    temp1->next->rollno=var;
                    var=temp1->age;
                    temp1->age=temp1->next->age;
                    temp1->next->age=var;
                   strcpy(name,temp1->name);
                    strcpy(temp1->name,temp1->next->name);
                    strcpy(temp1->next->name,name);
                }
               }
        }
    }
}
void removedup()
{
    struct list *temp,*temp1,*prev,*delptr;
    for(temp=start;temp->next!=NULL;temp=temp->next)
    {
        prev=temp;
        for(temp1=temp->next;temp1!=NULL;)
        {
            if(temp->rollno==temp1->rollno)
            {
                prev->next=temp1->next;
                delptr=temp1;
                temp1=temp1->next;
                delete delptr;
            }
            else
            {
                prev=temp1;
                temp1=temp1->next;
            }
        }
    }
}
int main()
{
        int n,roll,i,age;
        char name[50];
        int ch;
        char c;
        while(1)
        {
            cout<<"Press 1 to insert item\n";
            cout<<"Press 2 to sort\n";
            cout<<"Press 3 to remove duplicates\n";
            cout<<"Press 4 to traverse\n";
            cout<<"Press E to exit\n";
            cout<<"Enter your choice: ";
            cin>>ch;
            switch(ch)
            {
            case 1:
                cout<<"Enter Roll No,name and age\n";
                cin>>roll;
                cin>>name;
                cin>>age;
                insatend(roll,name,age);
                break;
            case 2:
                bubblesort();
                displist();
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 3:
                removedup();
                displist();
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 4:
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
