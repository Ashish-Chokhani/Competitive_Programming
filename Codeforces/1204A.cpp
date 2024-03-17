#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int noDigits=s.length();
    noDigits--;
    int ans=noDigits/2;
    int flag=0;
    for(int i=1;i<=noDigits;i++)
    {
        if(s[i]=='1')
        {
            flag=1;
            break;
        }
    }
    if(flag==1 || noDigits % 2!=0)
    ans++;
    cout<<ans<<"\n";
    return 0;
}