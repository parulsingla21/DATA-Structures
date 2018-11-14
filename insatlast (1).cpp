#include<iostream>
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
    struct list *temp;
    ptr=new list();
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
 for(temp=start;temp!=NULL;temp=temp->next)
 {
     cout<<temp->info<<" ";
 }
}
int main()
{
        int n,item,i;
        cout<<"Enter the number of elements to be entered";
        cin>>n;
        for(i=0;i<n;i++)
        {
            cout<<"Enter Element";
            cin>>item;
            insatbeg(item);
        }
        displist();
}
