#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> types(200005);
vector<vector<ll>> dp(200005, vector<ll>(4, 0));
vector<char> ch;

pair<ll, ll> findNext(ll val)
{
    vector<ll> v;
    pair<ll, ll> ans;
    for (ll i = 0; i < 3; i++)
    {
        if (val != i)
            v.push_back(i);
    }
    ans.first = v[0];
    ans.second = v[1];

    return ans;
}

ll find_min(ll a, ll b)
{
    return a <= b ? a : b;
}

char find_corresponding(ll v)
{
    if (v == 0)
        return 'R';
    else if (v == 1)
        return 'G';
    else
        return 'B';
}

ll findMini(ll ind1, ll ind2, ll row,ll n)
{
    if(dp[row][ind1] == dp[row][ind2])
    {
        if(row+1<=n && dp[row+1][ind1]>dp[row+1][ind2])
        return ind2;
        else
        return ind1;
    }
    if (dp[row][ind1] > dp[row][ind2])
        return ind1;
    else
        return ind2;
}

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == 'R')
            types[i] = 0;
        else if (s[i] == 'G')
            types[i] = 1;
        else if (s[i] == 'B')
            types[i] = 2;
    }

    for (ll ind = 1; ind <= n; ind++)
    {
        for (ll last = 0; last < 3; last++)
        {
            pair<ll, ll> cur = findNext(last);
            ll check1 = types[ind-1] != cur.first;
            ll check2 = types[ind-1] != cur.second;

            ll val1 = 1e12, val2 = 1e12;

            val1 = check1 + dp[ind - 1][cur.first];
            val2 = check2 + dp[ind - 1][cur.second];

            ll mini = find_min(val1, val2);

            dp[ind][last] = mini;
        }
    }

    ll val = min(dp[n][0], min(dp[n][1],dp[n][2]));

    // for(ll i=1;i<=n;i++)
    // {
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<"\n";
    // }

    cout << val << "\n";

    ll cur=0;
    if(dp[1][1]==1)
    cur=1;
    else if(dp[1][2]==1)
    cur=2;

    ch.push_back(find_corresponding(cur));

    for(ll i=2;i<=n;i++)
    {
        pair<ll,ll> next=findNext(cur);
        cur=findMini(next.first,next.second,i,n);
        ch.push_back(find_corresponding(cur));
    }
    for(auto it:ch)
    cout<<it;
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
