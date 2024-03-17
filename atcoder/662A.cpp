#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 1e6+2;
const ll p=1000000007;
ll fac[MAXN + 1];

void factorial(ll p)
{
    fac[0] = 1;
    for (ll i = 1; i <= MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % p;
    }
}

ll exp(ll x, ll y, ll p)
{
    ll res = 1;
    x %= p;
    while (y)
    {
        if (y & 1)
        {
            res *= x;
            res %= p;
        }
        x *= x;
        x %= p;
        y >>= 1;
    }
    return res;
}

void solve(){
    ll n;
    cin>>n;
    factorial(p);
    ll ans=fac[n];
    ll val=exp(2LL,n-1,p);
    ans=(ans-val+p)%p;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
