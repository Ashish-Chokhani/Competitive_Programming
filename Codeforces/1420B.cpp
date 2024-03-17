#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll findFirstSetBit(ll no)
{
    ll last=-1;
    for(ll i=0;i<63;i++)
    {
        ll bit=(no>>i)&1;
        if(bit)
        last=i;
    }
    return last;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<ll>counts(64,0);
    for(ll i=0;i<n;i++)
    {
        counts[findFirstSetBit(arr[i])]++;
    }
    ll ans=0;
    for(ll i=0;i<63;i++)
    {
        ll val=counts[i];
        ans+=(val*(val-1))/2;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}