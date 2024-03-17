#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<long long int> primes(1e6 + 1, 0);
map<ll, ll> mp;

void smallestPrime(long long int n)
{
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
}

// This function counts the frequency of each prime factor
vector<ll> primeFactors(long long int n)
{
    vector<ll> prime;
    long long int num = n;
    while (num > 1)
    {
        long long int p = primes[num];
        num = num / p;
        prime.push_back(p);
        while ((num % p) == 0)
        {
            num = num / p;
            prime.push_back(p);
        }
    }
    return prime;
}

void solve()
{
    ll n, k, maxi = 0;
    cin >> n >> k;
    smallestPrime(1e6);
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }
    for (ll i = 0; i < n; i++)
    {
        vector<ll> primes = primeFactors(arr[i]);
        map<ll, ll> mp1;
        for (auto it : primes)
        {
            mp1[it]++;
        }
        for (auto it : mp1)
        {
            mp[it.first] = max(mp[it.first], mp1[it.first]);
        }
    }
    vector<ll> primes = primeFactors(k);
    map<ll, ll> mp2;
    for (auto it : primes)
    {
        mp2[it]++;
    }
    for (auto it : mp2)
    {
        if (mp2[it.first] > mp[it.first])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
