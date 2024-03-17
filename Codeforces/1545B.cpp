#include <bits/stdc++.h>
using namespace std;

const long long int MAXN = 1e5+1,p=998244353;
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

void solve()
{
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int zeros = 0, ones = 0;
    for (long long int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zeros++;
        else
        {
            long long int temp = i;
            while (i < n && s[i] == '1')
            {
                i++;
            }
            ones += (i - temp) / 2;
            if(i<n && s[i]=='0')
            zeros++;
        }
    }
    cout<<choose(ones+zeros,ones,p)%p<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    factorial(p);
    inverses(p);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
