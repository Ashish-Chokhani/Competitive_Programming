#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll countchar(string &s, char c)
{
    ll cnt = 0;
    for (ll i = 0; i < 3; i++)
    {
        if (s[i] == c)
            cnt++;
    }
    return cnt;
}

void sortString(string &s)
{
    ll control = 0;
    ll cnt_w = countchar(s, 'w');
    ll cnt_i = countchar(s, 'i');
    ll cnt_n = countchar(s, 'n');
    for (ll i = 0; i < cnt_w; i++)
    {
        s[control++] = 'w';
    }
    for (ll i = 0; i < cnt_i; i++)
    {
        s[control++] = 'i';
    }
    for (ll i = 0; i < cnt_n; i++)
    {
        s[control++] = 'n';
    }
}

void addchar(string &s, char in, char out)
{
    for (ll i = 0; i < 3; i++)
    {
        if (s[i] == out)
        {
            s[i] = in;
            break;
        }
    }
    sortString(s);
}

void solve()
{
    ll n;
    cin >> n;
    vector<string> arr(n);
    map<pair<ll, pair<ll, ll>>, vector<ll>> mp;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr[i] = s;
        ll cnt_w = countchar(s, 'w');
        ll cnt_i = countchar(s, 'i');
        ll cnt_n = countchar(s, 'n');
        mp[{cnt_w, {cnt_i, cnt_n}}].push_back(i);
    }
    map<ll, ll> extra_w, extra_i, extra_n;
    ll n_op = 0;
    vector<string> ans;
    vector<pair<int, int>> index;
    map<ll, ll> done;
    for (ll i = 0; i < n; i++)
    {
        if (done[i])
            continue;

        string s = arr[i];
        ll cnt_w = countchar(s, 'w');
        ll cnt_i = countchar(s, 'i');
        ll cnt_n = countchar(s, 'n');

        if (cnt_w == 1 && cnt_i == 1 && cnt_n == 1)
        {
            done[i] = 1;
            continue;
        }

        if (cnt_w == 3 || cnt_i == 3 || cnt_n == 3)
        {
            continue;
        }

        ll r_w = abs(cnt_w - 2);
        ll r_i = abs(cnt_i - 2);
        ll r_n = abs(cnt_n - 2);

        if (mp[{r_w, {r_i, r_n}}].size() > 0)
        {
            vector<ll> v = mp[{r_w, {r_i, r_n}}];
            mp[{r_w, {r_i, r_n}}].pop_back();
            ll inde = v[v.size() - 1];
            if (!done[inde])
            {
                if (cnt_w == 0 && cnt_i > 1)
                    ans.push_back("iw");
                else if (cnt_w == 0 && cnt_n > 1)
                    ans.push_back("nw");
                else if (cnt_i == 0 && cnt_w > 1)
                    ans.push_back("wi");
                else if (cnt_i == 0 && cnt_n > 1)
                    ans.push_back("ni");
                else if (cnt_n == 0 && cnt_w > 1)
                    ans.push_back("wn");
                else if (cnt_n == 0 && cnt_i > 1)
                    ans.push_back("in");
                index.push_back({i + 1, inde + 1});
                done[i] = 1;
                done[inde] = 1;
                n_op++;
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (done[i])
            continue;
        string s = arr[i];
        ll cnt_w = countchar(s, 'w');
        ll cnt_i = countchar(s, 'i');
        ll cnt_n = countchar(s, 'n');
        if (cnt_w > 1)
            extra_w[i] = 1;
        ;
        if (cnt_i > 1)
            extra_i[i] = 1;
        if (cnt_n > 1)
            extra_n[i] = 1;
    }
    for (ll i = 0; i < n; i++)
    {
        if (done[i])
            continue;
        string s = arr[i];
        ll cnt_w = countchar(s, 'w');
        ll cnt_i = countchar(s, 'i');
        ll cnt_n = countchar(s, 'n');
        if (cnt_w < 1)
        {
            n_op++;
            auto it = extra_w.begin();
            ll ind = it->first;
            if (cnt_i > 1)
            {
                ll n_i = countchar(arr[ind], 'i');
                ll n_w = countchar(arr[ind], 'w');
                if (n_i >= 1)
                {
                    extra_i[ind] = 1;
                }
                if (n_w == 2)
                {
                    extra_w.erase(ind);
                }
                if (cnt_i == 2)
                {
                    extra_i.erase(i);
                }
                addchar(arr[i], 'w', 'i');
                addchar(arr[ind], 'i', 'w');
                index.push_back({i + 1, ind + 1});
                ans.push_back("iw");
            }
            else
            {
                ll n_n = countchar(arr[ind], 'n');
                ll n_w = countchar(arr[ind], 'w');
                if (n_n >= 1)
                {
                    extra_n[ind] = 1;
                }
                if (n_w == 2)
                {
                    extra_w.erase(ind);
                }
                if (cnt_n == 2)
                {
                    extra_n.erase(i);
                }
                addchar(arr[i], 'w', 'n');
                addchar(arr[ind], 'n', 'w');
                index.push_back({i + 1, ind + 1});
                ans.push_back("nw");
            }
        }
        s = arr[i];
        cnt_w = countchar(s, 'w');
        cnt_i = countchar(s, 'i');
        cnt_n = countchar(s, 'n');
        if (cnt_i < 1)
        {
            n_op++;
            auto it = extra_i.begin();
            ll ind = it->first;
            if (cnt_w > 1)
            {
                ll n_i = countchar(arr[ind], 'i');
                ll n_w = countchar(arr[ind], 'w');
                if (n_w >= 1)
                {
                    extra_w[ind] = 1;
                }
                if (n_i == 2)
                {
                    extra_i.erase(ind);
                }
                if (cnt_w == 2)
                {
                    extra_w.erase(i);
                }
                addchar(arr[i], 'i', 'w');
                addchar(arr[ind], 'w', 'i');
                index.push_back({i + 1, ind + 1});
                ans.push_back("wi");
            }
            else
            {
                ll n_n = countchar(arr[ind], 'n');
                ll n_i = countchar(arr[ind], 'i');
                if (n_n >= 1)
                {
                    extra_n[ind] = 1;
                }
                if (n_i == 2)
                {
                    extra_i.erase(ind);
                }
                if (cnt_n == 2)
                {
                    extra_n.erase(i);
                }
                addchar(arr[i], 'i', 'n');
                addchar(arr[ind], 'n', 'i');
                index.push_back({i + 1, ind + 1});
                ans.push_back("ni");
            }
        }
        s = arr[i];
        cnt_w = countchar(s, 'w');
        cnt_i = countchar(s, 'i');
        cnt_n = countchar(s, 'n');
        if (cnt_n < 1)
        {
            n_op++;
            auto it = extra_n.begin();
            ll ind = it->first;
            if (cnt_w > 1)
            {
                ll n_n = countchar(arr[ind], 'n');
                ll n_w = countchar(arr[ind], 'w');
                if (n_w >= 1)
                {
                    extra_w[ind] = 1;
                }
                if (n_n == 2)
                {
                    extra_n.erase(ind);
                }
                if (cnt_w == 2)
                {
                    extra_w.erase(i);
                }
                addchar(arr[i], 'n', 'w');
                addchar(arr[ind], 'w', 'n');
                index.push_back({i + 1, ind + 1});
                ans.push_back("wn");
            }
            else
            {
                ll n_n = countchar(arr[ind], 'n');
                ll n_i = countchar(arr[ind], 'i');
                if (n_i >= 1)
                {
                    extra_i[ind] = 1;
                }
                if (n_n == 2)
                {
                    extra_n.erase(ind);
                }
                if (cnt_i == 2)
                {
                    extra_i.erase(i);
                }
                addchar(arr[i], 'n', 'i');
                addchar(arr[ind], 'i', 'n');
                index.push_back({i + 1, ind + 1});
                ans.push_back("in");
            }
        }
    }
    cout << n_op << "\n";
    for (ll i = 0; i < n_op; i++)
    {
        cout << index[i].first << " " << ans[i][0] << " " << index[i].second << " " << ans[i][1] << "\n";
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