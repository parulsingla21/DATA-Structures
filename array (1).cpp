#include<iostream>
#include<stdlib.h>
using namespace std;
void insert(int arr[],int *n)
{
    int item,pos,i;
    cout<<"Enter the element you want to insert\n";
    cin>>item;
    cout<<"Enter the position where you want to insert item\n";
    cin>>pos;
    if(pos>*n)
    cout<<"Enter valid position\n";
    else
    {
    for(i=*n-1;i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[i+1]=item;
    *n=*n+1;
    }
}
void deletebypos(int arr[],int *n)
{
    int pos,i;
    cout<<"Enter the position from where you want to delete item\n";
    cin>>pos;
    if(pos>*n)
        cout<<"Enter valid position";
    else
    {
    for(i=pos;i<*n;i++)
        arr[i-1]=arr[i];
    *n=*n-1;
    }
}
void deletebyval(int arr[],int *n)
{
    int val,pos,i,flag=0;
    cout<<"Enter the value of the item you want to delete\n";
    cin>>val;
    for(i=0;i<*n;i++)
       {
           if(arr[i]==val)
           {
               pos=i;
               flag=1;
               break;
           }
       }
       if(flag==0)
        cout<<"Item not found\n";
       else
       {
       for(i=pos+1;i<*n;i++)
        arr[i-1]=arr[i];
        *n=*n-1;
       }
}
void display(int arr[],int n)
{
    int i;
    cout<<"Array: ";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<"\n";
}
void linearsearch(int arr[],int n)
{
    int i,pos,flag=0,val;
    cout<<"Enter the item to be searched\n";
    cin>>val;
    for(i=0;i<n;i++)
        if(arr[i]==val)
        {
        pos=i;
        flag=1;
        break;
        }
        if(flag==0)
            cout<<"Item not found\n";
        else
            cout<<val<<" is present at position "<<pos+1<<"\n";
}
void binarysearch(int arr[],int n)
{
    int i,beg,end,mid,val;
    cout<<"Enter the item to be searched\n";
    cin>>val;
   beg=0;
   end=n-1;
   mid=(beg+end)/2;
   while(arr[mid]!=val&&beg<=end)
   {
       if(val>arr[mid])
       {
           beg=mid+1;
       }
       else
       {
           end=mid-1;
       }
       mid=(beg+end)/2;
   }
   if(arr[mid]==val)
        cout<<val<<" is present at position "<<mid+1<<"\n";
    else
        cout<<"Item not found\n";
}
void bubblesort(int arr[],int n)
{
    int i,j,flag=0,temp;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
void selectionsort(int arr[],int n)
{
    int i,j,flag=0,temp;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
void insertionsort(int arr[],int n)
{
    int i, j, temp;
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        j = i-1;
        while(j>=0&&arr[j]>temp)
            {
                arr[j+1] = arr[j];
                j--;
            }
        arr[j+1] = temp;
    }
}
int main()
{
        int n,item,i,arr[100];
        int ch;
        char c;
        cout<<"Enter number of elements you want to insert in array\n";
        cin>>n;
        cout<<"Enter elements\n";
        for(i=0;i<n;i++)
            cin>>arr[i];
        system("CLS");
        while(1)
        {
            cout<<"Press 1 to insert item at any position\n";
            cout<<"Press 2 to delete item\n";
            cout<<"Press 3 to search item\n";
            cout<<"Press 4 sort array\n";
            cout<<"Press 5 to display array\n";
            cout<<"Press E to exit\n";
            cout<<"Enter your choice: ";
            cin>>ch;
            switch(ch)
            {
            case 1:
                insert(arr,&n);
                display(arr,n);
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 2:
                cout<<"1. Delete by position\n";
                cout<<"2. Delete by value\n";
                cout<<"Enter your choice\n";
                cin>>ch;
                if(ch==1)
                    deletebypos(arr,&n);
                else if(ch==2)
                    deletebyval(arr,&n);
                display(arr,n);
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 3:
                 cout<<"1. Linear Search\n";
                cout<<"2. Binary Search\n";
                cout<<"Enter your choice\n";
                cin>>ch;
                if(ch==1)
                linearsearch(arr,n);
                else if(ch==2)
                binarysearch(arr,n);
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 4:
                 cout<<"1. Bubble sort\n";
                cout<<"2. Selection sort\n";
                cout<<"3. Insertion sort\n";
                cout<<"Enter choice\n";
                cin>>ch;
                if(ch==1)
                    bubblesort(arr,n);
                else if(ch==2)
                    selectionsort(arr,n);
                else if(ch==3)
                    insertionsort(arr,n);
                display(arr,n);
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            case 5:
                display(arr,n);
                cout<<"Press C key to continue: ";
                cin>>c;
                break;
            default:
                display(arr,n);
                exit(0);
            }
            system("CLS");
            }
}
