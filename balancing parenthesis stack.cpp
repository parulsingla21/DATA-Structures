#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int checkpar(char str[])
{
    int i;
    stack <char> st;
    for (i=0;i<strlen(str);i++)
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
            st.push(str[i]);
        else
        {
            if(st.empty())
                return 0;
            else
            {
                 char c=st.top();
                st.pop();
                if((str[i]==')'&&c=='(')||(str[i]==']'&&c=='[')||(str[i]=='}'&&c=='{'))
                    continue;
                else
                    return 0;
            }
        }
    }
    if(st.empty())
        return 1;
    else
        return 0;
}
int main()
{
    char str[100];
    cout<<"Enter the expression\n";
    cin>>str;
    if(checkpar(str))
        cout<<"Balanced";
    else
        cout<<"Unbalanced";
}
