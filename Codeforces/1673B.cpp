#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int l = s.length();
    set<char> st;
    for (int i = 0; i < l; i++)
    {
        st.insert(s[i]);
    }
    int n = st.size();
    map<char, int> mp;
    set<char> V;
    for (int i = 0; i < n; i++)
    {
        V.insert(s[i]);
    }
    if (V.size() != n)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < l; i++)
    {
        int curr = mp[s[i]];
        mp[s[i]] = i;
        if ((i>=n) && (i - curr) != n)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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