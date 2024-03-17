#include <bits/stdc++.h>
using namespace std;

int N = 32000;
bool sieve[32001];
vector<int> primes;

void CreateSieve()
{
    for (int i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }

    for (int i = 2; i <= N; i++)
    {
        if (sieve[i] == true)
        {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto it : primes)
        {
            if (it * it > arr[i])
            {
                break;
            }
            if (arr[i] % it == 0)
            {
                if (mp[it] == 1)
                {
                    cout << "YES\n";
                    return;
                }
                else
                {
                    mp[it] = 1;
                }
                while (arr[i] % it == 0)
                {
                    arr[i] /= it;
                }
            }
        }
        if (arr[i] > 1)
        {
            if (mp[arr[i]] == 1)
            {
                cout << "YES\n";
                return;
            }
            else
            {
                mp[arr[i]] = 1;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    CreateSieve();
    while (t--)
    {
        solve();
    }
    return 0;
}
