#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>arr;
ll n;
ll N = 1000000;
bool sieve[1000001];
const long long int MAXN = 2030,p=998244353;
long long fac[MAXN + 1], inv[MAXN + 1];
vector<vector<ll>> dp(2*MAXN,vector<ll>(2*MAXN,-1));
map<ll,ll>freq;
 
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

void CreateSieve()
{
    for (ll i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }

    for (ll i = 2; i * i <= N; i++)
    {
        if (sieve[i] == true)
        {
            for (ll j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

ll findWays(ll ind,ll cnt,vector<ll>&primes)
{
    if(ind<0)
    {
        return cnt==n;
    }
    if(dp[ind][cnt]!=-1)
    return dp[ind][cnt]%p;
    
    ll pick=((inv[freq[primes[ind]]-1]%p)*findWays(ind-1,cnt+1,primes)%p)%p;
    ll not_pick=((inv[freq[primes[ind]]]%p)*(findWays(ind-1,cnt,primes)%p))%p;
    return dp[ind][cnt]=((pick%p)+(not_pick%p))%p;
}

void solve()
{
    factorial(p);
    inverses(p);
    CreateSieve();
    cin>>n;
    set<ll>distincts,not_primes;
    for(ll i=0;i<2*n;i++)
    {
        ll x;
        cin>>x;
        arr.push_back(x);
        freq[arr[i]]++;
        if(sieve[arr[i]])
        distincts.insert(arr[i]);
        else
        not_primes.insert(arr[i]);
    }
    vector<ll>primes(distincts.begin(),distincts.end());
    ll sz=primes.size();
    if(sz<n)
    {
        cout<<"0\n";
        return;
    }
    sort(arr.begin(),arr.end());
    ll val=findWays(sz-1,0,primes);
    ll ans=fac[n];
    for(auto it:not_primes)
    {
        ans=((ans%p)*(inv[freq[it]])%p);
    }
    ans=(ans%p*val%p)%p;
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
