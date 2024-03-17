typedef long long ll;

const ll int MAXN = 1e5+1,p=998244353;
ll fac[MAXN + 1], inv[MAXN + 1];
 
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
    for (ll int i = 1; i <= MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % p;
    }
}
 
/** Precomputes all modular inverse factorials from 0 to MAXN in O(n + log p) time */
void inverses(ll p)
{
    inv[MAXN] = exp(fac[MAXN], p - 2, p);
    for (ll int i = MAXN; i >= 1; i--)
    {
        inv[i - 1] = inv[i] * i % p;
    }
}
 
/** Computes nCr mod p */
ll choose(ll n, ll r, ll p)
{
    return fac[n] * inv[r] % p * inv[n - r] % p;
}

ll log_a_to_base_b(ll a, ll b)
{
    return (a > b - 1)
            ? 1 + log_a_to_base_b(a / b, b)
            : 0;
}

ll binexp(ll a, ll b, ll m)
{
    if (b == 0)
        return 1ll;
    if (b == 1)
        return a % m;
    if (b % 2)
        return (a * binexp(a, b - 1, m)) % m;
    return binexp((a * a) % m, b / 2, m);
}

// To calculate modular inverse
ll mod_inv(ll x)
{
    return binexp(x, p - 2, p);
}

void printNcR(int n, int r)
{
    if(r>n)
        return 0;
 
    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    ll p = 1, k = 1;
 
    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            // gcd of p, k
            ll m = __gcd(p, k);
 
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
    cout << p << endl;
}

ll MaximumWindow(vector<ll> &V)
{
    ll n = V.size();
    ll maxi = 0, max_so_far = 0;
    for (ll i = 0; i < n; i++)
    {
        ll val = max_so_far + V[i];
        max_so_far = max(val, 0LL);
        maxi = max(maxi, max_so_far);
    }
    return maxi;
}
