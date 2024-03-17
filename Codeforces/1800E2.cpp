#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;
    if(k>=n)
    {
        if(s!=t)
        {
            cout<<"NO\n";
            return;
        }
    }
    map<ll,ll>mp;
    vector<ll>arr1(26,0),arr2(26,0);
    for(ll j=n-k;j<k && j>=0 && j<n;j++)
    {
        if(s[j]!=t[j])
        {
        cout<<"NO\n";
        return;
        }
        mp[j]=1;
    }
    for(ll i=0;i<n;i++)
    {
        if(!mp[i])
        {
            arr1[s[i]-97]++;
            arr2[t[i]-97]++;
        }
    }
    for(ll i=0;i<26;i++)
    {
        if(arr1[i]!=arr2[i])
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    solve();
    }
}