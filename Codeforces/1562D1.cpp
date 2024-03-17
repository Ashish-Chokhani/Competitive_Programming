#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
            arr[i] = 1;
        else
            arr[i] = -1;
    }
    vector<int> sum(n, 0);
    int sign = -1;
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum[i] = (sign * arr[i]) + sum[i - 1];
        sign *= -1;
    }
    while (q--)
    {
        int l, r, sm = 0;
        cin >> l >> r;
        l--;
        r--;
        if (l >= 1)
            sm = sum[l - 1] - sum[r];
        else
            sm = sum[r];
        //cout<<sum[r]<<"\n";
        if (sm == 0)
        {
            cout << "0\n";
        }
        else if ((r - l + 1) % 2 != 0)
            cout << "1\n";
        else
            cout << "2\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
