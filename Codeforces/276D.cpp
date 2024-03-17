#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y)
{
    long long res = 1;
    while (y)
    {
        if (y & 1)
        {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}
 

ll findithBit(ll k,ll i)
{
    return (k>>i)&1;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    ll ans=0,val1=0,val2=0,i=0;
    for(i=62;i>=0;i--)
    {
        ll b1=findithBit(n,i);
        ll b2=findithBit(m,i);
        if(b1!=b2)
        break;
    }
    cout<<exp(2,i+1)-1<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
