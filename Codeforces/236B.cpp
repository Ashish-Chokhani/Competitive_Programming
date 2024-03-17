#include <bits/stdc++.h>
using namespace std;

int checkPrime(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if ((n / i) != i)
                cnt++;
        }
    }
    return cnt;
}

vector<int> calculate(int n)
{
    vector<int> sieve(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            sieve[j]++;
        }
    }
    return sieve;
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> arr = calculate(a * b * c);
    int ans = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                ans = (ans + arr[i * j * k]) % 1073741824;
            }
        }
    }
    cout << ans % 1073741824 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
