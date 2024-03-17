#include <bits/stdc++.h>
using namespace std;

int findMinimumIndex(vector<int> &b, vector<int> &index)
{
    int n = b.size();
    int mini = n + 1, mini_index = -1;
    for (int i = 0; i < index.size(); i++)
    {
        if (b[index[i]] < mini)
        {
            mini = b[index[i]];
            mini_index = index[i];
        }
    }
    return mini_index;
}

bool isSorted(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] < a[i - 1])
            return false;
    }
    return true;
}

vector<pair<int, int>> sortArray(vector<int> &a, vector<int> &b, vector<int> &sorted_a, vector<int> &sorted_b)
{
    int n = a.size();
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != sorted_a[i])
        {
            vector<int> index;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == sorted_a[i])
                    index.push_back(j);
            }
            int ind = findMinimumIndex(b, index);
            swap(a[i], a[ind]);
            swap(b[i], b[ind]);
            ans.push_back({i + 1, ind + 1});
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), sorted_a(n), sorted_b(n),temp_a(n),temp_b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sorted_a[i] = a[i];
        temp_a[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sorted_b[i] = b[i];
        temp_b[i] = b[i];
    }
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());
    vector<pair<int, int>> ans1 = sortArray(a,b, sorted_a, sorted_b);
    vector<pair<int, int>> ans2 = sortArray(b,a, sorted_b, sorted_a);
    vector<pair<int, int>> ans;
    ans.insert(ans.begin(),ans1.begin(),ans1.end());
    ans.insert(ans.end(),ans2.begin(),ans2.end());
    if (isSorted(a) && isSorted(b))
    {
        cout << ans.size() << "\n";
        for (auto it : ans)
        {
            cout << it.first << " " << it.second << "\n";
        }
    }
    else
        cout << "-1\n";
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