#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<long long int> smallestPrime(long long int n)
{
    vector<long long int> primes(n + 1, 0);
    for (long long int i = 1; i <= n; i++)
    {
        primes[i] = i;
    }
    for (long long int i = 2; i * i <= n; i++)
    {
        if (primes[i] == i)
        {
            for (long long int j = i * i; j <= n; j += i)
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

bool check(ll n)
{
    ll start=2;
    while(start<n)
    {
        start=start*2;
    }
    return start==n;
}

// This function counts the frequency of each prime factor
vector<long long int> countPrimes(long long int n)
{
    ll num = n;
    vector<ll> cnt(n + 1, 0);
    vector<ll>primes=smallestPrime(n);
    ll p;
    for (ll i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            p = i;
            break;
        }
    }
    while (num > 1)
    {
        num = num / p;
        cnt[p]++;
        while ((num % p) == 0)
        {
            num = num / p;
            cnt[p]++;
        }
        p=primes[num];
    }
    return cnt;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> cnt = countPrimes(n);
    ll maxi = 0;
    ll mul = 1;
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll it = cnt[i];
        maxi = max(maxi, it);
        if (it != 0)
        {
            ans = ans * i;
        }
    }
    sort(cnt.begin(), cnt.end());
    ll last = cnt[n];
    bool bad = true;
    for (ll i = n; i >= 1; i--)
    {
        if (cnt[i] != 0)
        {
            bad &= (cnt[i] == last) && (check(cnt[i]));
        }
    }
    if (bad)
        mul = 0;
    double v=log2(maxi);
    ll val=ceil(v)+mul;
    if(ans==n)
    val=0;
    cout << ans << " " << val << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
