#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n)
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
    return cnt == 2;
}

void solve()
{
    int n;
    cin >> n;
    if (checkPrime(n))
    {
        cout << "1\n";
        return;
    }
    else if (n % 2 != 0)
    {
        if (!checkPrime(n - 2))
        {
            cout << "3\n";
            return;
        }
    }
    cout << "2\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
