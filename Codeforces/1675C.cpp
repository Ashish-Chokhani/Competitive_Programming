#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int l=s.length();
    int one=0,zero=l-1;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='1')
        one=i;
    }
    for(int i=l-1;i>=0;i--)
    {
        if(s[i]=='0')
        zero=i;
    }
    cout<<(zero-one+1)<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}