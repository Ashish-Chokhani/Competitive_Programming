#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> index;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        index[arr[i]] = i + 1;
    }
    map<int, int> mp;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            if (gcd(i, j) == 1 && index[j] > mp[i])
                mp[i] = index[j];
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if(mp[arr[i]]!=0)
        ans=max(ans,i+1+mp[arr[i]]);
    }
    cout << ans << "\n";
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