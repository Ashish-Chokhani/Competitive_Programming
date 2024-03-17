#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> cost(100001);
vector<vector<ll>> dp(100001, vector<ll>(2, -1));

ll fun(ll index, ll isFlipped, ll n, string *s)
{
    if (index >= n)
        return 0;

    if (dp[index][isFlipped] != -1)
        return dp[index][isFlipped];

    bool type1 = true, type2 = true;
    if (isFlipped)
    {
        ll j = 0;
        ll pt = s[index - 1].length() - 1;
        ll flag = 1;
        while (pt >= 0 && j < s[index].length())
        {
            if (s[index - 1][pt] != s[index][j])
            {
                flag = 0;
                if (s[index - 1][pt] > s[index][j])
                    type1 = false;
                break;
            }
            pt--;
            j++;
        }
        if (flag == 1 && s[index - 1].length() > s[index].length())
        {
            type1 = false;
        }
        j = s[index].length() - 1;
        pt = s[index - 1].length() - 1;
        flag=1;
        while (pt >= 0 && j >= 0)
        {
            if (s[index - 1][pt] != s[index][j])
            {
                flag=0;
                if (s[index - 1][pt] > s[index][j])
                    type2 = false;
                break;
            }
            pt--;
            j--;
        }
        if (flag == 1 && s[index - 1].length() > s[index].length())
        {
            type2 = false;
        }
    }
    else
    {
        ll j = 0;
        ll pt = 0;
        ll flag=1;
        while (pt < s[index - 1].length() && j < s[index].length())
        {
            if (s[index - 1][pt] != s[index][j])
            {
                flag=0;
                if (s[index - 1][pt] > s[index][j])
                    type1 = false;
                break;
            }
            pt++;
            j++;
        }
        if (flag == 1 && s[index - 1].length() > s[index].length())
        {
            type1 = false;
        }
        j = s[index].length() - 1;
        pt = 0;
        flag=1;
        while (pt < s[index - 1].length() && j >= 0)
        {
            if (s[index - 1][pt] != s[index][j])
            {
                flag=0;
                if (s[index - 1][pt] > s[index][j])
                    type2 = false;
                break;
            }
            pt++;
            j--;
        }
        if (flag == 1 && s[index - 1].length() > s[index].length())
        {
            type2 = false;
        }
    }
    if (!type1 && !type2)
    {
        return dp[index][isFlipped] = 1e16;
    }
    ll flip_cost = 1e16, not_flip_cost = 1e16;
    if (type1)
    {
        not_flip_cost = fun(index + 1, 0, n, s);
    }
    if (type2)
    {
        flip_cost = cost[index] + fun(index + 1, 1, n, s);
    }
    return dp[index][isFlipped] = min(flip_cost, not_flip_cost);
}

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    string s[n];
    for (ll i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        s[i] = t;
    }
    ll ans1 = cost[0] + fun(1, 1, n, s);
    ll ans2 = fun(1, 0, n, s);
    ll ans = min(ans1, ans2);
    if (ans >= 1e16)
    {
        cout << "-1\n";
        return;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}