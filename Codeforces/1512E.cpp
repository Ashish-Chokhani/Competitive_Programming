#include <bits/stdc++.h>
using namespace std;

int lower(int k, int n, map<int, int> &mp)
{
    int ans = 0;
    for (int i = 1; i <= n && k > 0; i++)
    {
        if (!mp[i])
        {
            ans += i;
            k--;
        }
    }
    return ans;
}

int upper(int k, int n, map<int, int> &mp)
{
    int ans = 0;
    for (int i = n; i >= 1 && k > 0; i--)
    {
        if (!mp[i])
        {
            ans += i;
            k--;
        }
    }
    return ans;
}

bool isPossible(int i, int k, int n, int sum, map<int, int> &mp)
{
    if (mp[i] == 1)
        return false;
    else
    {
        mp[i] = 1;
        int l = lower(k - 1, n, mp);
        int u = upper(k - 1, n, mp);
        if (sum - i >= l && sum - i <= u)
        {
            return true;
        }
        else
        {
            mp[i] = 0;
            return false;
        }
    }
}

void solve()
{
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    map<int, int> mp;
    int k = r - l + 1;
    vector<int> ans;
    for (int i = 1; i <= n && s > 0; i++)
    {
        if (isPossible(i, k, n, s, mp))
        {
            ans.push_back(i);
            k--;
            s -= i;
        }
    }
    if (ans.size() != r - l + 1)
    {
        cout << "-1\n";
        return;
    }
    vector<int> rem;
    for(int i=1;i<=n;i++)
    {
        if(!mp[i])
        rem.push_back(i);
    }
    int i = 0, j = 0;
    for (int index = 1; index <= n; index++)
    {
        if(index<l || index>r)
        {
            cout<<rem[i]<<" ";
            i++;
        }
        else
        {
            cout<<ans[j]<<" ";
            j++;
        }
    }
    cout<<"\n";
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
