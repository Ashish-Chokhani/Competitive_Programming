#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fun(ll val)
{
    if(val<=2)
    return val;

    ll start=3;
    while(start*3<=val)
    {
        start*=3;
    }
    return 1+fun(val-start);
}

void solve()
{
    ll n,k;
    cin >> n >>k;
    ll value=fun(n);
    if(value<=k && k<=n && (k%2==n%2))
    cout<<"Yes\n";
    else
    cout<<"No\n";
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