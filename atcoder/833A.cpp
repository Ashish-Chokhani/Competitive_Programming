#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a,b;
    cin>>a>>b;
    ll val=a*b;
    ll cb_root=cbrt(val);
    ll val1=cb_root*cb_root*cb_root;
    if(val1==val && a%cb_root==0 && b%cb_root==0) cout<<"Yes\n";
    else cout<<"No\n";
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
