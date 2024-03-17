#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long int MAXN = 1e5 + 1, p = 1000000007;
long long fac[MAXN + 1], inv[MAXN + 1];

ll N = 70;
bool sieve[71];
map<ll, ll> loc;
vector<long long int> primes(71, 0);
vector<vector<int>>dp(71,vector<int>((1<<19)+1,-1));

void CreateSieve()
{
    for (ll i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }
    ll cnt = 0;
    for (ll i = 2; i <= N; i++)
    {
        if (sieve[i] == true)
        {
            loc[i] = cnt;
            cnt++;
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

long long exp(long long x, long long y, long long p)
{
    if(y<0)
    return 1;
    
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

/** Computes nCr mod p */
long long choose(long long n, long long r, long long p)
{
    return fac[n] * inv[r] % p * inv[n - r] % p;
}

vector<long long int> smallestPrime()
{
    for (long long int i = 1; i <= 70; i++)
    {
        primes[i] = i;
    }
    for (long long int i = 2; i * i <= 70; i++)
    {
        if (primes[i] == i)
        {
            for (long long int j = i * i; j <= 70; j += i)
            {
                if (primes[j] == j)
                {
                    primes[j] = i;
                }
            }
        }
    }
    return primes;
}

ll generateMask(ll num, ll cur_mask)
{
    ll next_mask=cur_mask;
    while (num > 1)
    {
        ll cnt=0;
        long long int pm = primes[num];
        cnt++;
        num = num / pm;
        while ((num % pm) == 0)
        {
            num = num / pm;
            cnt++;
        }
        if(cnt%2!=0)
        {
            next_mask=next_mask^(1<<loc[pm]);
        }
    }
    return next_mask;
}

ll solve(int n, int mask, map<ll, ll> &freq)
{
    if (n == 0)
    {
        return mask == 0;
    }
    if(dp[n][mask]!=-1)
    return dp[n][mask];
    ll even = 0, odd = 0;
    ll ways=exp(2,freq[n]-1,p)%p;
    even = (ways*solve(n - 1, mask, freq))%p;
    if(freq[n]>0)
    odd = (ways*solve(n - 1,generateMask(n,mask), freq))%p;
    return dp[n][mask]=(((even%p+odd%p)%p))%p;
}

void solve()
{
    ll n;
    cin >> n;
    map<ll,ll>mp;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >>x;
        mp[x]++;
    }
    CreateSieve();
    smallestPrime();
    factorial(p);
    inverses(p);
    cout<<(solve(70,0,mp)-1+p)%p<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
