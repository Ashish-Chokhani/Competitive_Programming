#include <bits/stdc++.h>
using namespace std;
 
vector<long long int> calcFactors(long long int n)
{
    vector<long long int> factors;
    for (long long int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if ((n / i) != i)
                factors.push_back(n / i);
        }
    }
    return factors;
}
 
vector<long long int> smallestPrime(long long int n)
{
    vector<long long int> primes(n + 1,0);
    for (long long int i = 2; i <= n; i++)
    {
        if (primes[i] == 0)
        {
            for (long long int j = i; j <= n; j += i)
            {
                primes[j]++;
            }
        }
    }
    return primes;
}
 
vector<long long int> countPrimes(long long int n)
{
    vector<long long int> primes = smallestPrime(n);
    vector<long long int> cnt(n + 1, 0);
    for (long long int i = 1; i <= n; i++)
    {
        long long int num = i;
        while (num > 1)
        {
            long long int p = primes[num];
            num = num / p;
            cnt[i]++;
            while ((num % p) == 0)
            {
                num = num / p;
            }
        }
    }
    return cnt;
}
 
vector<long long int> cnt = smallestPrime(20000000);
 
void solve()
{
    long long int c, d, x;
    cin >> c >> d >> x;
    vector<long long int> factors = calcFactors(x);
    long long int ans = 0;
    for (auto it : factors)
    {
        long long int num = (x / it) + d;
        if ((num % c) == 0)
        {
            ans += 1 << (cnt[num / c]);
        }
    }
    cout << ans << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
