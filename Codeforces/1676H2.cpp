#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<long long int> seg,lazy;

public:
    SGTree(long long int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

public:
    void build(long long int ind, long long int low, long long int high, vector<long long int> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        long long int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

public:
    void update(long long int ind, long long int low, long long int high, long long int l, long long int r, long long int val)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];

            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if (high < l || r < low)
            return;

        if (low >= l && high <= r)
        {
            seg[ind] += (high - low + 1) * val;
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        long long int mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    long long int query(long long int ind, long long int low, long long int high, long long int l, long long int r)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];

            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if (high < l || r < low)
            return 0;

        if (low >= l && high <= r)
        {
            return seg[ind];
        }
        long long int mid = (low + high) / 2;
        long long int left = query(2 * ind + 1, low, mid, l, r);
        long long int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    SGTree sg(n + 1);
    vector<long long int> freq(n, 0);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i]--;
        freq[arr[i]]++;
    }
    sg.build(0, 0, n - 1, freq);
    long long int sum = 0;
    for (long long int i = 0; i < n; i++)
    {
        long long int val = arr[i];
        freq[val]--;
        sg.update(0, 0, n - 1, val, val, -1);
        sum += sg.query(0, 0, n - 1, 0, val);
    }
    cout << sum << "\n";
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
