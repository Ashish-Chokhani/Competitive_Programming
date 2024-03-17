#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<char> ch(k);
    for (int i = 0; i < k; i++)
    {
        cin >> ch[i];
    }
    string y(ch.begin(), ch.end());
    map<char, int> mp;
    for (int i = 0; i < k; i++)
    {
        mp[y[i]] = 1;
    }
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]] == 1)
            arr[i] = 1;
    }
    int l = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            l++;
        else
        {
            ans.push_back(l + 1);
            l = 0;
        }
    }
    if (ans.size() == 0)
    {
        cout << "0\n";
        return;
    }
    ans[0]--;
    cout << *max_element(ans.begin(), ans.end()) << "\n";
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
    return 0;
}