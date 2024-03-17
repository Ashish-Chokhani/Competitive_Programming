#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    if (!(n & 1))
    {
        ll first = 1 << 20, second = 1 << 19;
        for (ll i = 0; i < n - 1; i += 2)
        {
            arr[i] = first;
            arr[i + 1] = second;
            first++;
            second++;
        }
        if (n % 4 == 2)
        {
            arr[n - 1] -= (1 << 19);
            arr[0]=0;
        }
    }
    else
    {
        ll first = 1 << 20, second = 1;
        for (ll i = 0; i < n - 1; i += 2)
        {
            arr[i] = first;
            arr[i + 1] = second;
            first++;
            second++;
        }
        arr[n - 1] = first;
        if (n % 4 == 1)
        {
            arr[0] = 0;
        }
    }
    for (auto it : arr)
        cout << it << " ";
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
}