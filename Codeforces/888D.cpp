#include <bits/stdc++.h>
using namespace std;

const long long int MAXN = 1e5 + 1, p = 10000000007;
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


// Function to find the nCr
long long int printNcR(long long int n,long long  int r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            // gcd of p, k
            long long m = __gcd(p, k);

            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;

            n--;
            r--;
        }

        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }

    else
        p = 1;

    // if our approach is correct p = ans and k =1
    return p;
}

long long int log_a_to_base_b(long long int a, long long int b)
{
    return (a > b - 1)
               ? 1 + log_a_to_base_b(a / b, b)
               : 0;
}

long long int Multiply(long long int k)
{
    if (k == 1)
        return 0;
    if (k == 2 || k == 0)
        return 1;
    if (k == 3)
        return 2;
    if (k == 4)
        return 9;
    return 0;
}

void solve()
{
    long long int n, k;
    cin >> n >> k;
    long long int ans = 0;
    while (k >= 0)
    {
        ans += (printNcR(n, k) * Multiply(k));
        k--;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    factorial(p);
    inverses(p);
    solve();
    return 0;
}