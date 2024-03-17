#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, s1, s2;
    cin >> n >> s1 >> s2;
    ll s_min = min(s1, s2);
    ll s_max = max(s1, s2);
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        arr[i] = {x, i};
    }
    sort(arr.rbegin(), arr.rend());
    vector<ll> adj[2];
    for (auto it : arr)
    {
        ll val = it.first;
        ll cost1 = (adj[0].size() + 1) * s_min;
        ll cost2 = (adj[1].size() + 1) * s_max;
        if (cost1 <= cost2)
        {
            adj[0].push_back(it.second + 1);
        }
        else
        {
            adj[1].push_back(it.second + 1);
        }
    }
    if (s1 <= s2)
    {
        cout << adj[0].size() << " ";
        for (auto it : adj[0])
            cout << it << " ";
        cout << "\n";
        cout << adj[1].size() << " ";
        for (auto it : adj[1])
            cout << it << " ";
        cout << "\n";
    }
    else
    {
        cout << adj[1].size() << " ";
        for (auto it : adj[1])
            cout << it << " ";
        cout << "\n";
        cout << adj[0].size() << " ";
        for (auto it : adj[0])
            cout << it << " ";
        cout << "\n";
    }
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
