#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<int> seg, lazy;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
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
    void update(int ind, int low, int high, int l, int r, int val)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] = 0;

            if (low != high)
            {
                lazy[2 * ind + 1] = 1;
                lazy[2 * ind + 2] = 1;
            }
            lazy[ind] = 0;
        }

        if (high < l || r < low)
            return;

        if (low >= l && high <= r)
        {
            seg[ind] = 0;
            if (low != high)
            {
                lazy[2 * ind + 1] = 1;
                lazy[2 * ind + 2] = 1;
            }
            return;
        }
        int mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    int query(int ind, int low, int high, int l, int r)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] = 0;

            if (low != high)
            {
                lazy[2 * ind + 1] = 1;
                lazy[2 * ind + 2] = 1;
            }
            lazy[ind] = 0;
        }
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
    vector<pair<int,int>>D;
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
        cin>>a;
        D.push_back({a,i});
    }
    sort(D.begin(),D.end());
    reverse(D.begin(),D.end());
    SGTree Sg(n);
    Sg.build(0, 0, n - 1, arr);
    int county = 0;
    for (int i = 0; i < n; i++)
    {
        int l = D[i].second + 1;
        int r = D[i].second + D[i].first;
        // cout<<"l="<<l<<" "<<"r="<<r<<"\n";
        if (l <= r && l < n && r < n)
        {
            int x = Sg.query(0, 0, n - 1, l, r);
            // cout<<"x="<<x<<"\n";
            if (x != 0)
            {
                Sg.update(0, 0, n - 1, l, r, 1);
                county++;
            }
        }
    }
    int y = Sg.query(0, 0, n - 1, 0, n - 1);
    if (y != 0)
        county = -1;
    cout << county << "\n";
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