#include<iostream>
#include<stdlib.h>
using namespace std;
int n,f=-1,r=-1;
void insertqueue(int a[],int item)
{
    int i;
 if((f==0&&r==n-1))
    {
        cout<<"Overflow";
        char c;
        cout<<"\nPress C to continue: ";
            cin>>c;
        return;
    }
    if(f==-1&&r==-1)
        {
            f=0;
            r=0;
        }
        else if(f!=0&&r==n-1)
        {
            i=f;
            for(int j=f;j<=r;j++)
            {
                a[j-i]=a[j];
            }
            f=f-i;
            r=r-i+1;
        }
        else
        {
            r++;
        }
        a[r]=item;
}
void traversequeue(int a[])
{
    int i;
    if(f==-1&&r==-1)
    {
        cout<<"Empty\n";
        return;
    }
        for(i=f;i<=r;i++)
        {
            cout<<a[i]<<" ";
        }
}
void deletequeue(int a[])
{
    if(f==-1&&r==-1)
    {
        cout<<"Underflow\n";
        char c;
        cout<<"\nPress C to continue: ";
            cin>>c;
        return;
    }
    int item;
    item=a[f];
    cout<<item<<"\n";
    if(f==r)
    {
        f=-1;
        r=-1;
    }
else
    f++;
}
int main()
{
    int arr[100],i,ch,item;
    char c;
    cout<<"Enter value of n\n";
    cin>>n;
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
            insertqueue(arr,item);
            break;
        case 2:
           deletequeue(arr);
            traversequeue(arr);
             char c;
        cout<<"\nPress C to continue: ";
            cin>>c;
            break;
        case 3:
            traversequeue(arr);
            cout<<"\nPress C to continue: ";
            cin>>c;
            break;
        case 4:
            traversequeue(arr);
            exit(0);
        }
        system("CLS");
    }
}
