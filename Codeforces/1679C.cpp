#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<long long int> seg, lazy;

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
        // if (lazy[ind] != 0)
        // {
        //     seg[ind] = lazy[ind];

        //     if (low != high)
        //     {
        //         lazy[2 * ind + 1] = val;
        //         lazy[2 * ind + 2] = val;
        //     }
        //     lazy[ind] = 0;
        // }

        if (high < l || r < low)
            return;

        if (low >= l && high <= r)
        {
            seg[ind] = val;
            // if (low != high)
            // {
            //     lazy[2 * ind + 1] = val;
            //     lazy[2 * ind + 2] = val;
            // }
            return;
        }
        long long int mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    long long int query(long long int ind, long long int low, long long int high, long long int l, long long int r)
    {
        // if (lazy[ind] != 0)
        // {
        //     seg[ind] += (high - low + 1) * lazy[ind];

        //     if (low != high)
        //     {
        //         lazy[2 * ind + 1] += lazy[ind];
        //         lazy[2 * ind + 2] += lazy[ind];
        //     }
        //     lazy[ind] = 0;
        // }

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
    long long int n, q;
    cin >> n >> q;
    SGTree st1(n + 1), st2(n + 1);
    vector<long long int> row(n, 0);
    vector<long long int> col(n, 0);
    st1.build(0, 0, n - 1, row);
    st2.build(0, 0, n - 1, col);
    while (q--)
    {
        long long int type;
        cin >> type;
        if (type == 1)
        {
            long long int x, y;
            cin >> x >> y;
            x--;
            y--;
            if(row[x]==0)
            st1.update(0, 0, n - 1, x, x, 1);
            row[x]++;
            if(col[y]==0)
            st2.update(0, 0, n - 1, y, y, 1);
            col[y]++;
        }
        else if (type == 2)
        {
            long long int x, y;
            cin >> x >> y;
            x--;
            y--;
            row[x]--;
            if(row[x]==0)
            st1.update(0, 0, n - 1, x, x,0);
            col[y]--;
            if(col[y]==0)
            st2.update(0, 0, n - 1, y, y,0);
        }
        else if (type == 3)
        {
            long long int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--;
            y1--;
            x2--;
            y2--;
            long long int x = x2 - x1 + 1;
            long long int y = y2 - y1 + 1;
            if (st1.query(0, 0, n - 1, x1, x2) == x || st2.query(0, 0, n - 1, y1, y2) == y)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}