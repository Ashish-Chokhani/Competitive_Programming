#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int room = (i + arr[i]) % n;
        if (room < 0)
        {
            room += n;
        }
        if (mp[room])
        {
            cout << "NO\n";
            return;
        }
        else
        {
            mp[room] = 1;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}