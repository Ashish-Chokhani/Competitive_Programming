#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n);
    vector<ll>freq(n+m+1,0);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]=m+1;
    }
    for(ll i=1;i<=m;i++)
    {
        ll p,v;
        cin>>p>>v;
        p--;
        freq[arr[p]]-=m+1-i;
        freq[v]+=m+1-i;
        arr[p]=v;
    }
    ll ans=0;
    for(ll i=0;i<=n+m;i++)
    {
        ans+=freq[i]*m;
        if(freq[i]>=2)
        {
            ll ch=(freq[i]*(freq[i]-1))/2;
            ans-=ch;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
