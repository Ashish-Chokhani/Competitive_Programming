#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        if (n - i <= k)
        {
            cout << "1000 ";
            k -= n - i;
        }
        else
        {
            if (k == 0)
            {
                while (i < n)
                {
                    cout << "-1 ";
                    i++;
                }
            }
            else
            {
                cout << k << " ";
                i++;
                ll cnt = 0;
                while (i < n)
                {
                    cnt++;
                    if (cnt <= k - 1)
                        cout << "-1 ";
                    else
                        cout << "-2 ";
                    i++;
                }
            }
        }
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}