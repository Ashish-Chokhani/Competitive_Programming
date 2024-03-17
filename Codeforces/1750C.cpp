#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        // cout<<(s1[i]-'0')<<" "<<(1 - (s2[i] -'0'))<<"\n";
        if ((s1[i] - '0') != (1 - (s2[i] - '0')))
        {
            flag = 0;
            break;
        }
    }
    if (flag == 0 && !(s1 == s2))
    {
        cout << "NO\n";
        return;
    }
    else
    {
        cout << "YES\n";
        vector<pair<int, int>> ans;
        vector<int> county(n + 1, 0);
        if (flag == 1)
        {
            ans.push_back({1, n});
        }
        for (int i = 1; i <= n; i++)
        {
            if (s2[i - 1] == '1')
            {
                if (i == 1)
                {
                    ans.push_back({1, n});
                    ans.push_back({2, n});
                }
                else
                {
                    county[i]++;
                    county[i - 1]++;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (county[i] % 2 == 1)
            {
                ans.push_back({1, i});
            }
        }
        cout << ans.size() << "\n";
        for (auto it : ans)
        {
            cout << it.first << " " << it.second << "\n";
        }
    }
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