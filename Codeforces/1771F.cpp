#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<int> seg;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }

public:
    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

public:
    int query(int ind, int low, int high, int l, int r)
    {
        if (high < l || r < low)
            return 0;

        if (low >= l && high <= r)
        {
            return seg[ind];
        }
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr(n);
    vector<pair<int, int>> D;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            arr[i] = 0;
        else
            arr[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        D.push_back({a, i});
    }
    sort(D.begin(), D.end());
    reverse(D.begin(), D.end());
    SGTree Sg(n);
    Sg.build(0, 0, n - 1, arr);
}

int main()
{
    solve();
    return 0;
}
