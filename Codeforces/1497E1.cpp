#include <bits/stdc++.h>
using namespace std;

vector<int> primes(10000001, 0);
vector<int> smallestPrime(int n)
{
    for (int i = 1; i <= n; i++)
    {
        primes[i] = i;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
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

// This function counts the frequency of each prime factor
vector<int> countPrimes(int i)
{
    vector<int> V;
    int num = i;
    while (num > 1)
    {
        int p = primes[num], county = 0;
        num = num / p;
        county++;
        while ((num % p) == 0)
        {
            num = num / p;
            county++;
        }
        if((county % 2) != 0)
        V.push_back(p);
    }
    return V;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int segments = 0, flag = 1;
    map<vector<int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        vector<int> V = countPrimes(arr[i]);
        if (!mp[V] || flag == 1)
        {
            mp[V] = 1;
            flag = 0;
        }
        else
        {
            mp.clear();
            mp[V] = 1;
            segments++;
        }
    }
    cout << segments+1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    smallestPrime(10000000);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}