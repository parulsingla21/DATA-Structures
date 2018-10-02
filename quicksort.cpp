#include<iostream>
using namespace std;
int top=-1;
int arr[100];
int quick(int beg,int end)
{
    int p;
int loc,left,right;
loc=beg;
left=beg;
right=end;
while(1)
{
    while(arr[right]>=arr[loc]&&right>loc)
    {
        right=right-1;
    }
    if(loc==right)
    {
    return loc;
    }
    p=arr[right];
    arr[right]=arr[loc];
    arr[loc]=p;
    loc=right;
    while(arr[left]<=arr[loc]&&left<loc)
    {
        left=left+1;
    }
    if(loc==left)
    {
    return loc;
    }
    p=arr[left];
    arr[left]=arr[loc];
    arr[loc]=p;
    loc=left;
    loc=beg;
}
}
int main()
{
    int i,j,lower[100],upper[100],n,beg,end,loc;
    top++;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>arr[i];
    lower[top]=0;
    upper[top]=n-1;
    while(top!=-1)
    {
        beg=lower[top];
        end=upper[top];
        top--;
        loc=quick(beg,end);
        if(beg<loc-1)
        {
            top++;
            lower[top]=beg;
            upper[top]=loc-1;
        }
        if(loc+1<end)
        {
            top++;
            lower[top]=loc+1;
            upper[top]=end;
        }
    }
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
