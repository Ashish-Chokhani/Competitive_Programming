#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,x;
    cin >>n>>x;
    vector<ll> arr(n);
    map<ll,ll>mp,freq;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
         mp[arr[i]]++;
    }
    for(auto it:mp)
    {
        if(it.second>=2)
        {
            cout<<"0\n";
            return;
        }
    }
    for(ll i=0;i<n;i++)
    {
        ll val=arr[i]&x;
        if(mp[val]>=(arr[i]==val)+1)
        {
            cout<<"1\n";
            return;
        }
    }
    for(ll i=0;i<n;i++)
    {
        arr[i]&=x;
        freq[arr[i]]++;
    }
    for(auto it:freq)
    {
        if(it.second>=2)
        {
            cout<<"2\n";
            return;
        }
    }
    cout<<"-1\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}