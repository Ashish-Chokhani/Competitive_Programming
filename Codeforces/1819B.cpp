#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    ll tot_area = 0;
    map<ll,multiset<ll>> mp1, mp2;
    ll max_h = 0, max_w = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        arr[i] = {x, y};
        tot_area += x * y;
        max_h = max(max_h, x);
        max_w = max(max_w, y);
        mp1[x].insert(y);
        mp2[y].insert(x);
    }
    set<pair<ll, ll>> ans;
    ll h = max_h, w, flag = 0;
    if (tot_area % h == 0)
    {
        w = tot_area / h;
        for (ll i = 0; i < n; i++)
        {
            if (mp1[h].size() > 0)
            {
                ll val = *mp1[h].begin();
                w -= val;
                mp1[h].erase(mp1[h].begin());
                mp2[val].erase(mp2[val].find(h));
            }
            else if (mp2[w].size() > 0)
            {
                ll val = *mp2[w].begin();
                h -= val;
                mp2[w].erase(mp2[w].begin());
                mp1[val].erase(mp1[val].find(w));
            }
            else
                flag = 1;
        }
        if (!flag)
            ans.insert({max_h, tot_area / max_h});
    }
    mp1.clear();
    mp2.clear();
    for (ll i = 0; i < n; i++)
    {
        ll x = arr[i].first;
        ll y = arr[i].second;
        mp1[x].insert(y);
        mp2[y].insert(x);
    }
    w = max_w, flag = 0;
    if (tot_area % w == 0)
    {
        h = tot_area / w;
        for (ll i = 0; i < n; i++)
        {
            if (mp2[w].size() > 0)
            {
                ll val = *mp2[w].begin();
                h -= val;
                mp2[w].erase(mp2[w].begin());
                mp1[val].erase(mp1[val].find(w));
            }
            else if (mp1[h].size() > 0)
            {
                ll val = *mp1[h].begin();
                w -= val;
                mp1[h].erase(mp1[h].begin());
                mp2[val].erase(mp2[val].find(h));
            }
            else
                flag = 1;
        }
        if (!flag)
            ans.insert({tot_area / max_w, max_w});
    }
    cout << ans.size() << "\n";
    for (auto it : ans)
    {
        cout << it.first << " " << it.second << "\n";
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
    return 0;
}
