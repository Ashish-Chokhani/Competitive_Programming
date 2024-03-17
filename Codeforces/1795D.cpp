#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

const long long int MAXN = 3e5+1,p=998244353;
long long fac[MAXN + 1],inv[MAXN + 1];

/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y, long long p)
{
    long long res = 1;
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
 
/** Precomputes n! from 0 to MAXN. */
void factorial(long long p)
{
    fac[0] = 1;
    for (long long int i = 1; i <= MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % p;
    }
}

/** Precomputes all modular inverse factorials from 0 to MAXN in O(n + log p) time */
void inverses(long long p)
{
    inv[MAXN] = exp(fac[MAXN], p - 2, p);
    for (long long int i = MAXN; i >= 1; i--)
    {
        inv[i - 1] = inv[i] * i % p;
    }
}

ll findMinimum(ll a,ll b,ll c)
{
    ll mini=a;
    mini=min(mini,b);
    mini=min(mini,c);
    ll cnt=0;
    if(a==mini)
    cnt++;
    if(b==mini)
    cnt++;
    if(c==mini)
    cnt++;
    return cnt;
}

void solve()
{
    factorial(p);
    inverses(p);
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll val=n/3;
    ll ans=fac[val];
    ans=((ans%p)*(inv[val/2]%p))%p;
    ans=((ans%p)*(inv[val/2]%p))%p;
    for(ll i=0;i<n;i+=3)
    {
        ans=((ans%p)*(findMinimum(arr[i],arr[i+1],arr[i+2])%p))%p;
    }
    cout<<ans<<"\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}