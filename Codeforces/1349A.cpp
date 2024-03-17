#include <bits/stdc++.h>
using namespace std;

vector<int> primes(200001, 0);
void smallestPrime(int n)
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
}

// This function counts the frequency of each prime factor
void countPrimes(int num, map<int, vector<int>> &mp)
{
    while (num > 1)
    {
        int cnt = 0;
        int p = primes[num];
        num = num / p;
        cnt++;
        while ((num % p) == 0)
        {
            num = num / p;
            cnt++;
        }
        mp[p].push_back(cnt);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        countPrimes(arr[i], mp);
    }
    long long int ans = 1;
    for (auto it : mp)
    {
        vector<int> V = it.second;
        sort(V.begin(), V.end());
        int l = V.size();
        if (l == n)
        {
            ans = ans * pow(it.first, V[1]);
        }
        else if (l == n - 1)
        {
            ans = ans * pow(it.first, V[0]);
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    smallestPrime(200000);
    solve();
    return 0;
}