#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<int> sum(n, 0);
    int cnt = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                cnt++;
                sum[i]++;
            }
        }
    }
    if ((cnt % n) != 0)
    {
        cout << "-1\n";
        return;
    }
    cnt = cnt / n;
    vector<pair<int, pair<int, int>>> ans;
    for (int col = 0; col < m; col++)
    {
        vector<int> more, less;
        for (int i = 0; i < n; i++)
        {
            if (sum[i] > cnt && arr[i][col])
                more.push_back(i);
            if (sum[i] < cnt && !arr[i][col])
                less.push_back(i);
        }
        for(int i=0;i<min(more.size(),less.size());i++)
        {
            --sum[more[i]];
            ++sum[less[i]];
            ans.push_back({col,{more[i],less[i]}});
        }
    }
    cout << ans.size() << "\n";
    for (auto it : ans)
    {
        cout << it.second.first + 1 << " " << it.second.second + 1 << " " << it.first + 1 << "\n";
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
