#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x,y;
    cin>>x>>y;
    ll ans=0;
    for(ll k=1;k*k<=1e9;k++)
    {
       ll lb=k+2,rb=min(y+1,x/k);
       if(rb>=lb) ans+=rb-lb+1;
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
