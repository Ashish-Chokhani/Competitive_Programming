#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<char,long long int>mp;
    for(long long int i=1;i<=k;i++)
    {
        char c;
        cin>>c;
        mp[c]=1;
    }
    long long int len=0;
    long long int ans=0;
    for(long long int i=0;i<n;i++)
    {
        if(mp[s[i]])
        len++;
        else
        {
            ans+=(len*(len+1))/2;
            len=0;
        }
    }
    ans+=(len*(len+1))/2;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}