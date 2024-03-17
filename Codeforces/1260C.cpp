#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long int n, long long int x, long long int last)
{
    long long int m = x - n;
    if ((last < 0 && m > 0) || (last > 0 && m < 0))
        return false;
    last = abs(last);
    m = abs(m);
    return (m % last) == 0;
}

void solve()
{
    long long int n, x;
    cin>>n>>x;
    string s;
    cin >> s;
    long long int zerosCnt = 0, onesCnt = 0;
    map<long long int, long long int> mp;
    set<long long int> st;
    long long int last = -1;
    for (long long int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            onesCnt++;
        else
            zerosCnt++;
        long long int pre = zerosCnt - onesCnt;
        mp[pre]++;
        st.insert(pre);
        last = pre;
    }
    if (last == 0)
    {
        for (auto it : st)
        {
            if (it == x)
            {
                cout << "-1\n";
                return;
            }
        }
        cout << "0\n";
        return;
    }
    long long int ans = 0;
    if(x==0)
    ans++;
    for (auto it : st)
    {
        if (isPossible(it, x, last))
            ans += mp[it];
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}