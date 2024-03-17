#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<pair<ll, ll>> arr1, arr2, arr3, arr4;

bool sortbyCond(const pair<ll, ll> &a,
                const pair<ll, ll> &b)
{
    if (a.first != b.first)
        return (a.first > b.first);
    else
        return (a.second > b.second);
}

bool sortbyCond1(const pair<ll, ll> &a,
                const pair<ll, ll> &b)
{
    if (a.first != b.first)
        return (a.first > b.first);
    else
        return (a.second < b.second);
}

bool sortbyCond2(const pair<ll, ll> &a,
                const pair<ll, ll> &b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
        return (a.second > b.second);
}

pair<char, char> fun(ll type, ll isGoing)
{
    if (type == 1)
    {
        if (isGoing)
            return {'R', 'U'};
        else
            return {'D', 'L'};
    }
    else if (type == 2)
    {
        if (isGoing)
            return {'L', 'U'};
        else
            return {'D', 'R'};
    }
    else if (type == 3)
    {
        if (isGoing)
            return {'L', 'D'};
        else
            return {'U', 'R'};
    }
    else
    {
        if (isGoing)
            return {'R', 'D'};
        else
            return {'U', 'L'};
    }
}

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (x >= 0 && y >= 0)
            arr1.push_back({x, y});
        else if (x < 0 && y >= 0)
            arr2.push_back({x, y});
        else if (x < 0 && y < 0)
            arr3.push_back({x, y});
        else
            arr4.push_back({x, y});
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(),sortbyCond1);
    sort(arr3.begin(), arr3.end(), sortbyCond);
    sort(arr4.begin(), arr4.end(), sortbyCond2);

    vector<char> ans;
    vector<ll>chu;
    ll cnt = 0;

    for (auto it : arr1)
    {
        ll dx = abs(it.first);
        ll dy = abs(it.second);
        pair<char, char> ch;
        ch = fun(1, 1);
        if (dx)
        {
            ans.push_back('1');
            chu.push_back(dx);
            ans.push_back(ch.first);
            cnt++;
        }
        if (dy)
        {
            ans.push_back('1');
            chu.push_back(dy);
            ans.push_back(ch.second);
            cnt++;
        }
        ans.push_back('2');
        cnt++;
        ch = fun(1, 0);
        if (dy)
        {
            ans.push_back('1');
            chu.push_back(dy);
            ans.push_back(ch.first);
            cnt++;
        }
        if (dx)
        {
            ans.push_back('1');
            chu.push_back(dx);
            ans.push_back(ch.second);
            cnt++;
        }
        ans.push_back('3');
        cnt++;
    }
    for (auto it : arr2)
    {
        ll dx = abs(it.first);
        ll dy = abs(it.second);
        pair<char, char> ch;
        ch = fun(2, 1);
        if (dx)
        {
            ans.push_back('1');
            chu.push_back(dx);
            ans.push_back(ch.first);
            cnt++;
        }
        if (dy)
        {
            ans.push_back('1');
            chu.push_back(dy);
            ans.push_back(ch.second);
            cnt++;
        }
        ans.push_back('2');
        cnt++;
        ch = fun(2, 0);
        if (dy)
        {
            ans.push_back('1');
            chu.push_back(dy);
            ans.push_back(ch.first);
            cnt++;
        }
        if (dx)
        {
            ans.push_back('1');
            chu.push_back(dx);
            ans.push_back(ch.second);
            cnt++;
        }
        ans.push_back('3');
        cnt++;
    }
    for (auto it : arr3)
    {
        ll dx = abs(it.first);
        ll dy = abs(it.second);
        pair<char, char> ch;
        ch = fun(3, 1);
        if (dx)
        {
            ans.push_back('1');
            chu.push_back(dx);
            ans.push_back(ch.first);
            cnt++;
        }
        if (dy)
        {
            ans.push_back('1');
            chu.push_back(dy);
            ans.push_back(ch.second);
            cnt++;
        }
        ans.push_back('2');
        cnt++;
        ch = fun(3, 0);
        if (dy)
        {
            ans.push_back('1');
            chu.push_back(dy);
            ans.push_back(ch.first);
            cnt++;
        }
        if (dx)
        {
            ans.push_back('1');
            chu.push_back(dx);
            ans.push_back(ch.second);
            cnt++;
        }
        ans.push_back('3');
        cnt++;
    }
    for (auto it : arr4)
    {
        ll dx = abs(it.first);
        ll dy = abs(it.second);
        pair<char, char> ch;
        ch = fun(4, 1);
        if (dx)
        {
            ans.push_back('1');
            chu.push_back(dx);
            ans.push_back(ch.first);
            cnt++;
        }
        if (dy)
        {
            ans.push_back('1');
            chu.push_back(dy);
            ans.push_back(ch.second);
            cnt++;
        }
        ans.push_back('2');
        cnt++;
        ch = fun(4, 0);
        if (dy)
        {
            ans.push_back('1');
            chu.push_back(dy);
            ans.push_back(ch.first);
            cnt++;
        }
        if (dx)
        {
            ans.push_back('1');
            chu.push_back(dx);
            ans.push_back(ch.second);
            cnt++;
        }
        ans.push_back('3');
        cnt++;
    }
    cout<<cnt<<"\n";
    int i=0,j=0;
    while(cnt--)
    {
        if(ans[i]=='1')
        {
            cout<<ans[i]<<" "<<chu[j++]<<" "<<ans[i+1]<<"\n";
            i+=2;
        }
        else
        {
        cout<<ans[i]<<"\n";
        i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}