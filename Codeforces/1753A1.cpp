#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int cntzero = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            cntzero++;
    }
    if ((n - cntzero) % 2 != 0)
    {
        cout << "-1\n";
        return;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        while (i < n && arr[i] == 0)
        {
            ans.push_back({i + 1, i + 1});
            i++;
        }
        int curr = i;
        i++;
        while (i < n && arr[i] == 0)
            i++;
        if (i<n && (arr[curr] != arr[i])) // check boundary
        {
            for (int j = curr; j <= i; j++)
                ans.push_back({j + 1, j + 1});
        }
        else if(i<n)
        {
            int l = i - curr - 1;
            if (l == 0)
            {
                ans.push_back({curr + 1, i + 1});
            }
            else if(l>0)
            {
                ans.push_back({curr + 1, i - 1});
                ans.push_back({i, i + 1});
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto it : ans)
    {
        cout << it.first << " " << it.second << "\n";
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