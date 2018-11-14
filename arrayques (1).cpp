#include<iostream>
using namespace std;
int main()
{
    int arr1[50],arr2[50],distinct[100],common[100],n,m,i,j,flag=0,k=0,h=0;
    cout<<"Enter the value of m for array1\n";
    cin>>m;
    cout<<"Enter values\n";
     for(i=0;i<m;i++)
     {
        cin>>arr1[i];
     }
    cout<<"Enter the value of n for array2\n";
    cin>>n;
    cout<<"Enter values\n";
    for(i=0;i<n;i++)
     {
        cin>>arr2[i];
     }
     for(i=0;i<m;i++)
     {
         flag=0;
         for(j=0;j<n;j++)
         {
             if(arr1[i]==arr2[j])
             {
                 common[k++]=arr1[i];
                 flag=1;
                 break;
             }
         }
         if(flag==0)
            distinct[h++]=arr1[i];
     }
     for(i=0;i<n;i++)
     {
         for(j=0;j<k;j++)
         {
             flag=0;
             if(arr2[i]==common[j])
             {
                 flag=1;
                 break;
             }
         }
         if(flag==0)
            distinct[h++]=arr2[i];
     }
     cout<<"Common: ";
     flag=0;
     for(i=0;i<k;i++)
     {
        cout<<common[i]<<" ";
        flag=1;
     }
     if(flag==0)
        cout<<"No common\n";
        cout<<"\nDistinct: ";
        flag=0;
    for(i=0;i<h;i++)
       {
        cout<<distinct[i]<<" ";
        flag=1;
     }
     if(flag==0)
      cout<<"No distinct\n";
}
