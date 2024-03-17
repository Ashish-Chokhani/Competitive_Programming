#include <bits/stdc++.h>
using namespace std;

const long long int MAXN = 2e5 + 1, p = 998244353;
long long fac[MAXN + 1], inv[MAXN + 1];

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

/** Computes nCr mod p */
long long choose(long long n, long long r, long long p)
{
    return fac[n] * inv[r] % p * inv[n - r] % p;
}

int N = 300000;
bool sieve[3000001];
void CreateSieve()
{
    for (int i = 1; i <= N; i++)
    {
        sieve[i] = true;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

void solve()
{
    long long int n, m;
    cin >> n >> m;
    vector<long long int> arr(n + 1,1);
    long long int start = 1;
    long long int ans=1,ans1=0,r;
    for (long long int i = 1; i <= n; i++)
    {
        if (sieve[i])
            start = (start * i);
        if(start>m)
        break;
        r = m / start;
        r%=p;
        ans*=r;
        ans%=p;
        ans1+=ans;
        ans1%=p;
    }
    long long int l=0;
    for(int i=1;i<=n;i++)
    {
    l=(l+exp(m,i,p)%p);
    l%=p;
    }
    cout<<(l+(6*p)-ans1)%p<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    factorial(p);
    inverses(p);
    CreateSieve();
    solve();
}