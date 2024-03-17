#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long int MAXN = 1e5 + 1, p = 1000000007;
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
    if (n < r)
        return 0;

    return fac[n] * inv[r] % p * inv[n - r] % p;
}

ll MaximumLength(ll i, ll k, vector<ll> &dp1, vector<ll> *adj, vector<ll> &arr, ll n)
{
    if (i < 0)
        return 0;

    if (dp1[i] != -1)
        return dp1[i];

    ll element = arr[i];
    vector<ll> V = adj[element];
    ll ind = lower_bound(V.begin(), V.end(), i) - V.begin();

    ll ans = 0;
    if (ind >= k - 1)
    {
        ll new_ind = V[ind - k + 1];
        ans = max(ans, 1 + MaximumLength(new_ind - 1, k, dp1, adj, arr, n));
    }
    ans = max(ans, MaximumLength(i - 1, k, dp1, adj, arr, n));
    return dp1[i] = ans;
}

ll fun(ll i, ll rem, ll k, vector<vector<ll>> &dp2, vector<ll> *adj, vector<ll> &arr, ll n, map<ll, ll> &mp)
{
    if (rem == 0)
        return 1;

    if (i < 0)
        return rem == 0;

    ll ans = 0;

    ll element = arr[i];
    ll ind = lower_bound(adj[element].begin(),adj[element].end(), i) - adj[element].begin();
    
    for(ll j=0;j<ind;j++)
    {
    ans += fun(adj[element][j] - 1, rem - 1, k, dp2, adj, arr, n, mp);
    }
    if(i>=1 && arr[i]!=arr[i-1])
    ans += fun(i - 1, rem, k, dp2, adj, arr, n, mp);
    return ans;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (k == 1)
    {
        cout << "1\n";
        return;
    }
    vector<ll> adj[n + 2];
    for (ll i = 0; i < n; i++)
    {
        adj[arr[i]].push_back(i);
    }
    vector<ll> dp1(n + 2, -1);
    ll maxLen = MaximumLength(n - 1, k, dp1, adj, arr, n) * k;
    map<ll, ll> mp;
    vector<vector<ll>> dp2(n + 2, vector<ll>(n + 2, -1));
    for (ll j = n - 1; j >= 0; j--)
    {
        ll i = j;
        while (i >= 0 && arr[j] == arr[i])
        {
            i--;
        }
        mp[j] = i + 1;
    }
    cout << fun(n - 1, maxLen, k, dp2, adj, arr, n, mp) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    factorial(p);
    inverses(p);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
// Modulo
