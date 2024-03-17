#include <bits/stdc++.h>
using namespace std;

bool isPossible(int k, string &s, int n, int distinct)
{
    int county = 0;
    int j = 0;
    map<int, int> mp;
    while (j < k)
    {
        mp[s[j]]++;
        if(mp[s[j]]==1)
        county++;
        j++;
        if (county == distinct)
            return true;
    }
    int i = 0;
    j = k;
    while (j < n)
    {
        mp[s[i]]--;
        if (mp[s[i]] == 0)
            county--;
        i++;
        mp[s[j]]++;
        if (mp[s[j]] == 1)
            county++;
        j++;
        if (county == distinct)
            return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<int, int> mp;
    int distinct = 0;
    for (int i = 0; i < n; i++)
    {
        if (!mp[s[i]])
        {
            mp[s[i]] = 1;
            distinct++;
        }
    }
    int l = distinct, r = n, ans = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (isPossible(mid, s, n, distinct))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}