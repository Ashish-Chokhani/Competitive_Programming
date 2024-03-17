#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve()
{
    ll a,b;
    cin >> a >>b;
    ll ans=a+b;
    for(ll k=2;k<=1e5;k++)
    {
        ll val=(a+k-1)/k + (b+k-1)/k + (k-1);
        ans=min(ans,val);
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