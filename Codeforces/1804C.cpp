#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve()
{
    ll n,x,p;
    cin>>n>>x>>p;
    for(ll l=1;l<=min(2*n,p);l++)
    {
        ll val=(l*(l+1))/2;
        if((val+x)%n==0)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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