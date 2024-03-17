#include <bits/stdc++.h>
using namespace std;

bool isCheck(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j >= 1 && arr[i][j] < arr[i][j - 1])
            {
                return false;
            }
        }
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, -1)), temp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            temp[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        sort(temp[i].begin(), temp[i].end());
    }
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] != arr[i][j])
                s.insert(j);
        }
    }
    if (s.size() == 0)
    {
        cout << "1 1\n";
        return;
    }
    else if (s.size() >= 3)
    {
        cout << "-1\n";
        return;
    }
    else
    {
        int j1, j2;
        vector<int> p;
        for (auto it : s)
        {
            p.push_back(it);
        }
        j1 = p[0], j2 = p[1];
        for (int i = 0; i < n; i++)
        {
            swap(arr[i][j1], arr[i][j2]);
        }
        if (isCheck(arr))
        {
            cout << (j1 + 1) << " " << (j2 + 1) << "\n";
            return;
        }
    }
    cout << "-1\n";
    return;
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