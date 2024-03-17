#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    long long int l=s.length();
    long long int sum=0;
    for(long long int i=0;i<l;i++)
    {
    sum+=s[i]-96;
    }
    if(l%2==0)
    {
        cout<<"Alice "<<sum<<"\n";
    }
    else if(l==1)
    {
        cout<<"Bob "<<sum<<"\n";
    }
    else
    {
        cout<<"Alice "<<(sum-(2*min(s[0]-96,s[l-1]-96)))<<"\n";
    }
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}