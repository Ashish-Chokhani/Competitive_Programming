#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isDiagonal(ll row, ll col, ll n, ll m, ll dir)
{
    return (row == 0 && col == 0 && dir == 3) || (row == n - 1 && col == m - 1 && dir == 1) || (row == 0 && col == m - 1 && dir == 0) || (row == n - 1 && col == 0 && dir == 2);
}

ll findNext(ll row, ll col, ll dir, ll n, ll m)
{
    if (isDiagonal(row, col, n, m, dir))
    {
        return dir >= 2 ? dir - 2 : dir + 2;
    }
    if (dir == 0)
        return row == 0 ? 1 : 3;
    if (dir == 1)
        return col==m-1 ? 2 : 0;
    if (dir == 2)
        return row == n-1 ? 3 : 1;
    if (dir == 3)
        return col == 0 ? 0 : 2;
    return -1;
}

bool isAvailable(ll row, ll col, ll dir, ll i2, ll j2)
{
    if (dir == 0 || dir == 2)
    {
        if (dir == 0)
            return (i2 <= row) && (j2 >= col) && (j2 == col - i2 + row);

        return (i2 >= row) && (j2 <= col) && (j2 == col - i2 + row);
    }
    else if (dir == 1 || dir == 3)
    {
        if (dir == 1)
            return (i2 >= row) && (j2 >= col) && (j2 == col + i2 - row);
        return (i2 <= row) && (j2 <= col) && (j2 == col + i2 - row);
    }
    return false;
}

pair<ll, ll> findLast(ll row, ll col, ll dir, ll n, ll m)
{
    if (dir == 0)
    {
        ll val = min(row, m - 1 - col);
        return {row - val, col + val};
    }
    else if (dir == 1)
    {
        ll val = min(n - 1 - row, m - 1 - col);
        return {row + val, col + val};
    }
    else if (dir == 2)
    {
        ll val = min(n - 1 - row, col);
        return {row + val, col - val};
    }
    else if (dir == 3)
    {
        ll val = min(row, col);
        return {row - val, col - val};
    }
    return {-1, -1};
}

void solve()
{
    ll n, m, i1, i2, j1, j2;
    string d;
    map<pair<pair<ll,ll>,ll>,ll>mp;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2;
    i1--;
    i2--;
    j1--;
    j2--;
    cin >> d;
    ll dir;
    if (d == "UR")
        dir = 0;
    else if (d == "DR")
        dir = 1;
    else if (d == "DL")
        dir = 2;
    else
        dir = 3;
    ll cnt = 0;
    while (1)
    {
        if (isAvailable(i1, j1, dir, i2, j2))
        {
            cout << cnt << "\n";
            return;
        }
        else
        {
            pair<ll, ll> val = findLast(i1, j1, dir, n, m);
            i1 = val.first;
            j1 = val.second;
            if(mp[{{i1,j1},dir}])
            {
                cout<<"-1\n";
                return;
            }
            mp[{{i1,j1},dir}]=1;
            dir = findNext(i1, j1, dir, n, m);
        }
        cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}