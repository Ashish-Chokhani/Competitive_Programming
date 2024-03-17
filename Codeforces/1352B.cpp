#include <bits/stdc++.h>
using namespace std;

bool isEven(int n)
{
    return n % 2 == 0;
}

bool isOdd(int n)
{
    return n % 2 != 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if ((isOdd(n) && isEven(k)) || (n < k))
    {
        cout << "NO\n";
        return;
    }
    if ((isEven(n) && isEven(k)) || (isOdd(n) && isOdd(k)))
    {
        cout << "YES\n";
        for (int i = 1; i <= k - 1; i++)
        {
            cout << "1 ";
        }
        cout << n - (k - 1) << "\n";
    }
    if(isEven(n) && isOdd(k))
    {
        if (n < 2 * k)
        {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for (int i = 1; i <= k - 1; i++)
        {
            cout << "2 ";
        }
        cout << n - (2*(k - 1)) << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
