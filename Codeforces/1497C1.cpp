#include <bits/stdc++.h>
using namespace std;

void answer(int n, int k)
{
    if (n % k == 0)
    {
        cout << n / k << " " << n / k << " " << n / k << "\n";
        return;
    }
    if (n % 2 != 0)
    {
        cout << "1 " << (n - 1) / 2 << " " << (n - 1) / 2 << "\n";
        return;
    }
    if (n % 4 == 0)
    {
        cout << n / 2 << " " << n / 4 << " " << n / 4 << "\n";
        return;
    }
    cout << "2 " << (n - 2) / 2 << " " << (n - 2) / 2 << "\n";
    return;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    while(k>3)
    {
        cout<<"1 ";
        n--;
        k--;
    }
    answer(n,k);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}