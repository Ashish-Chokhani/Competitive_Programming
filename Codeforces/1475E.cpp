#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e4;
const ll p=1000000007;
long long fac[MAXN + 1], inv[MAXN + 1];
 
/** Computes x^y modulo p in O(log p) time. */
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
 
/** Precomputes n! from 0 to MAXN. */
void factorial(ll p)
{
    fac[0] = 1;
    for (ll i = 1; i <= MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % p;
    }
}
 
/** Precomputes all modular inverse factorials from 0 to MAXN in O(n + log p) time */
void inverses(ll p)
{
    inv[MAXN] = exp(fac[MAXN], p - 2, p);
    for (ll i = MAXN; i >= 1; i--)
    {
        inv[i - 1] = inv[i] * i % p;
    }
}
 
/** Computes nCr mod p */
ll choose(ll n, ll r, ll p)
{
    return fac[n] * inv[r] % p * inv[n - r] % p;
}

void solve()
{
    ll n,k;
    cin>>n >>k;
    vector<ll>arr(n);
    map<ll,ll>freq,req;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    sort(arr.begin(),arr.end());
    ll cnt=0,i=n-1;
    while(cnt<k)
    {
        req[arr[i]]++;
        i--;
        cnt++;
    }
    ll ans=1;
    for(auto it:req)
    {
        ll val=it.first;
        ll req_freq=it.second;
        ans*=choose(freq[val],it.second,p);
        ans%=p;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    factorial(p);
    inverses(p);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
