#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isSet(ll &mask, ll bit)
{
    return (mask >> bit) & 1;
}

void Set(ll &mask, ll bit)
{
    mask = mask | (1 << bit);
}

vector<ll> fun(ll ind, ll mask, ll flag, ll l, ll k, string &s,map<pair<ll,pair<ll,ll>>,vector<ll>>&mp,map<pair<ll,pair<ll,ll>>,ll>&isMapped)
{
    vector<ll> ans;
    if (ind >= l)
        return mp[{ind,{mask,flag}}]=ans;
    
    if(isMapped[{ind,{mask,flag}}])
    return mp[{ind,{mask,flag}}];

    ll setBits = __builtin_popcount(mask);

    ll rem = k - setBits;

    if (rem >= 1 && flag)
    {
        for (ll i = ind; i < l; i++)
            ans.push_back(0);
        isMapped[{ind,{mask,flag}}]=1; 
        return mp[{ind,{mask,flag}}]=ans;
    }

    if (rem == 0 && flag)
    {
        ll mini = 9;
        for (ll i = 0; i <= 9; i++)
        {
            if (isSet(mask, i))
            {
                mini = i;
                break;
            }
        }
        for (ll i = ind; i < l; i++)
            ans.push_back(mini);
        isMapped[{ind,{mask,flag}}]=1; 
        return mp[{ind,{mask,flag}}]=ans;
    }

    if (!rem && !flag)
    {
        ll mini = -1, second = -1;
        ll val = s[ind] - '0';
        for (ll i = val; i <= 9; i++)
        {
            if (isSet(mask, i))
            {
                mini = i;
                break;
            }
        }
        if (mini == -1)
        {
            isMapped[{ind,{mask,flag}}]=1; 
            return mp[{ind,{mask,flag}}]=ans;
        }

        if (mini > val)
        {
            vector<ll> v = fun(ind + 1, mask, 1, l, k, s, mp,isMapped);
            if (v.size() == l - ind - 1)
            {
                ans.push_back(mini);
                for (auto it : v)
                    ans.push_back(it);
                isMapped[{ind,{mask,flag}}]=1; 
                return mp[{ind,{mask,flag}}]=ans;
            }
        }

        vector<ll> v = fun(ind + 1, mask, 0, l, k, s,mp,isMapped);
        if (v.size() == l - ind - 1)
        {
            ans.push_back(mini);
            for (auto it : v)
                ans.push_back(it);
            isMapped[{ind,{mask,flag}}]=1; 
            return mp[{ind,{mask,flag}}]=ans;
        }

        for (ll i = mini + 1; i <= 9; i++)
        {
            if (isSet(mask, i))
            {
                second = i;
                break;
            }
        }

        if (second == -1)
        {
            isMapped[{ind,{mask,flag}}]=1; 
            return mp[{ind,{mask,flag}}]=ans;
        }

        v = fun(ind + 1, mask, 1, l, k, s,mp,isMapped);
        if (v.size() == l - ind - 1)
        {
            ans.push_back(second);
            for (auto it : v)
                ans.push_back(it);
            isMapped[{ind,{mask,flag}}]=1; 
            return mp[{ind,{mask,flag}}]=ans;
        }
    }
    ll val = s[ind] - '0';
    ll mask1 = mask;
    Set(mask1, val);
    vector<ll> v = fun(ind + 1, mask1, 0, l, k, s,mp,isMapped);
    if (v.size() == l - ind - 1)
    {
        ans.push_back(val);
        for (auto it : v)
            ans.push_back(it);
        isMapped[{ind,{mask,flag}}]=1; 
        return mp[{ind,{mask,flag}}]=ans;
    }
    mask1 = mask;
    ll value = val != 9 ? val + 1 : val;
    Set(mask1, value);
    vector<ll> v1 = fun(ind + 1, mask1, val != 9, l, k, s,mp,isMapped);
    ans.push_back(value);
    for (auto it : v1)
        ans.push_back(it);
    isMapped[{ind,{mask,flag}}]=1; 
    return mp[{ind,{mask,flag}}]=ans;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    string s = to_string(n);
    int l = s.length();
    map<pair<ll,pair<ll,ll>>,vector<ll>> mp;
    map<pair<ll,pair<ll,ll>>,ll> isMapped;
    vector<ll> ans = fun(0, 0, 0, l, k, s, mp,isMapped);
    for (auto it : ans)
    {
        cout << it;
    }
    cout << "\n";
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
