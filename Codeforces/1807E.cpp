#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n),p(n,0);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    p[0]=arr[0];
    for(ll i=1;i<n;i++)
    {
        p[i]=arr[i]+p[i-1];
    }
    ll l=0,r=n-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        cout<<"? "<<mid-l+1<<" ";
        for(ll i=l;i<=mid;i++)
        {
            cout<<i+1<<" ";
        }
        cout<<"\n";
        ll val;
        cin>>val;
        ll a=0;
        if(l>=1)
        a=p[l-1];
        if(val!=p[mid]-a)
        r=mid-1;
        else
        l=mid+1;
    }
    cout<<"! "<<l+1<<"\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}