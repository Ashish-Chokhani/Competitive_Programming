#include <bits/stdc++.h>
using namespace std;

int N = 15000000;
vector<int> primes(15000001);
bool sieve[15000001];
void CreateSieve()
{
    for (int i = 1; i <= N; i++)
    {
        sieve[i] = true;
        primes[i] = i;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
                if (primes[j] == j)
                    primes[j] = i;
            }
        }
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
    int g = arr[0];
    for (int i = 1; i < n; i++)
    {
        g = gcd(arr[i], g);
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / g;
        if (arr[i] > 1)
            flag = 0;
    }
    if (flag)
    {
        cout << "-1\n";
        return;
    }
    int ans = 0;
    vector<int> cnt(15000001, 0);
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        while (num > 1)
        {
            int p=primes[num];
            cnt[p]++;
            num = num / p;
            ans = max(ans, cnt[p]);
            while (num % p == 0)
            {
                num = num / p;
            }
        }
    }
    cout << n - ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CreateSieve();
    solve();
    return 0;
}
