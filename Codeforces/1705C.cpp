#include <bits/stdc++.h>
using namespace std;

long long int fun(long long int index, vector<long long int> &pos, vector<pair<long long int, long long int>> &range)
{
    if (index <= pos[0])
        return index;
    long long int block = lower_bound(pos.begin(), pos.end(), index) - pos.begin();
    long long int gap = index - pos[block - 1]-1;
    return fun(range[block].first + gap, pos, range);
}

void solve()
{
    long long int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<long long int> pos(c + 1);
    vector<pair<long long int, long long int>> range(c + 1);
    pos[0] = n;
    for (long long int i = 1; i <= c; i++)
    {
        long long int l, r;
        cin >> l >> r;
        pos[i] = pos[i - 1] + (r - l + 1);
        range[i] = {l, r};
    }
    for (long long int i = 1; i <= q; i++)
    {
        long long int k;
        cin >> k;
        long long int index = fun(k, pos, range);
        cout << s[index - 1] << "\n";
    }
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