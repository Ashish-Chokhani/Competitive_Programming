#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> arr(13, 0);

ll findDigits(ll n)
{
    ll cnt = 0;
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

ll MSB(ll n, ll dig)
{
    ll start = 1;
    for (ll i = 1; i <= dig - 1; i++)
    {
        start *= 10;
    }
    return n / start;
}

ll generate(ll dig)
{
    ll start = 1;
    for (ll i = 1; i <= dig - 1; i++)
    {
        start *= 10;
    }
    return start;
}

ll fun(ll n)
{
    if(n<10)
    {
        return n>=4;
    }
    ll dig = findDigits(n);
    ll fixed = arr[dig - 1];
    ll msb = MSB(n, dig);
    ll val=msb*generate(dig);
    if(msb<4)
    {
        return (msb*fixed)+fun(n-val);
    }
    else if(msb>4)
    {
        return (msb*fixed)+(val/msb)-fixed+fun(n-val);
    }
    else
    {
        return (msb*fixed)+(n-val+1);
    }
}

ll range(ll l,ll r)
{
    if(l>r)
    return 0;
    return fun(r)-fun(l-1);
}

void solve()
{
    ll k;
    cin >> k;
    ll val=range(1,k);
    ll p1=k+1;
    ll ans=k+val;
    while(range(p1,ans)>0)
    {
        ll v=range(p1,ans);
        p1=ans+1;
        ans+=v;
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
    arr[0] = 0;
    ll start = 1;
    for (ll i = 1; i < 13; i++)
    {
        arr[i] = arr[i - 1] * 9 + start;
        start *= 10;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}
