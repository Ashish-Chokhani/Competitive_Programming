#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(1001, vector<int>(1001, 0));
vector<int> ans;

int findMax(vector<pair<int, int>> &v, vector<int> &r, int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        int pick = 0, not_pick = 0;
        for (int j = 1; j <= k; j++)
        {
            if (v[i - 1].first <= r[j - 1])
                pick = v[i - 1].second + dp[i - 1][j - 1];
            not_pick = dp[i - 1][j];
            dp[i][j] = max(pick, not_pick);
        }
    }
    return dp[n][k];
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n), V(n);
    map<pair<int, int>,vector<int>> mp1;
    map<int,vector<int>> mp2;
    map<pair<int,int>,int> index1;
    map<int,int> index2;
    for (int i = 0; i < n; i++)
    {
        int c, p;
        cin >> c >> p;
        v[i] = {c, p};
        mp1[v[i]].push_back(i);
        V[i] = {c, p};
    }
    sort(v.begin(), v.end());
    int k;
    cin >> k;
    vector<int> r(k), R(k);
    for (int i = 0; i < k; i++)
    {
        cin >> r[i];
        mp2[r[i]].push_back(i);
        R[i] = r[i];
    }
    sort(r.begin(), r.end());
    int val = findMax(v, r, n, k);
    int i = n, j = k;
    while (i > 0 && j > 0)
    {
        if (v[i - 1].first <= r[j - 1])
        {
            if (v[i - 1].second + dp[i - 1][j - 1] > dp[i - 1][j])
            {
                ans.push_back(i - 1);
                i--;
                j--;
            }
            else
                i--;
        }
        else
        {
            i--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << " " << val << "\n";
    i = k - 1, j = ans.size() - 1;
    for (int m = 1; m <= ans.size(); m++)
    {
        int i1=index1[v[ans[j]]];
        int i2=index2[r[i]];
        index1[v[ans[j]]]++;
        index2[r[i]]++;
        cout << mp1[v[ans[j]]][i1] + 1 << " " << mp2[r[i]][i2] + 1 << "\n";
        i--;
        j--;
    }
}

int main()
{
    solve();
    return 0;
}
