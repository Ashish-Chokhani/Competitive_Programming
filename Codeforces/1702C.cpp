#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (mp[arr[i]].first == 0)
            mp[arr[i]].first = (i + 1);
        else
            mp[arr[i]].second = (i + 1);
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        if ((mp[a].first == 0) || (mp[b].first == 0))
            cout << "NO\n";
        else if (mp[a].first <= max(mp[b].first,mp[b].second))
            cout << "YES\n";
        else
            cout << "NO\n";
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