#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long int smallestPrime(long long int n)
{
    for (long long int i = 2; i * i <= n; i++)
    {
        if ((n % i) == 0)
            return i;
    }
    return n;
}

// This function counts the frequency of each prime factor
vector<long long int> countPrimes(long long int n)
{
    vector<long long int> cnt;
    long long int num = n;
    while (num > 1)
    {
        long long int p = smallestPrime(num);
        cnt.push_back(p);
        num = num / p;
        while ((num % p) == 0)
        {
            num = num / p;
        }
    }
    return cnt;
}

long long int log_a_to_base_b(long long int a, long long int b)
{
    return (a > b - 1)
            ? 1 + log_a_to_base_b(a / b, b)
            : 0;
}

long long int calcG(long long int n, long long int num)
{
    long long int county = 0, x = num;
    long long int z = log_a_to_base_b(n,num);
    while (z--)
    {
        county += (n / num);
        num *= x;
    }
    return county;
}

long long exp(long long x, long long y)
{
    long long res = 1;
    x %= MOD;
    while (y)
    {
        if (y & 1)
        {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void solve()
{
    long long int x, n;
    cin >> x >> n;
    vector<long long int> primes = countPrimes(x);
    long long int ans = 1;
    for (auto it : primes)
    {
        long long int num = it;
        long long int g = calcG(n, num);
        // cout<<g<<"\n";
        ans = (ans * (exp(it, g))) % MOD;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
