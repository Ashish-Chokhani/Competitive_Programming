#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans = -1;
ll dp[10][10][21][2][2];

void initdp()
{
    for (ll a = 0; a < 10; a++)
    {
        for (ll b = 0; b < 10; b++)
        {
            for (ll c = 0; c < 20; c++)
            {
                for (ll d = 0; d < 2; d++)
                {
                    for (ll e = 0; e < 2; e++)
                    {
                        dp[a][b][c][d][e] = -1;
                    }
                }
            }
        }
    }
}

vector<ll> intTOVect(ll n)
{
    vector<ll>dig;
    while(n>0)
    {
        ll rem=n%10;
        dig.push_back(rem);
        n/=10;
    }
    reverse(dig.begin(),dig.end());
    return dig;
}

ll StringTOInt(string s)
{
    ll val=0;
    for(ll i=0;i<s.length();i++)
    {
        val=(val*10)+(s[i]-48);
    }
    return val;
}


ll fun(ll low, ll high, ll pos, ll lb, ll ub, vector<ll> &arr, vector<ll> &l, vector<ll> &r, ll ndig,vector<ll>&ans)
{
    if (pos >= ndig)
    {
        if(ans.size()==0)
        {
            ans.resize(arr.size());
            ans=arr;
        }
        return 1;
    }

    ll dig1 = l[pos];
    ll dig2 = r[pos];

    if(dp[low][high][pos][lb][ub]!=-1)
    return dp[low][high][pos][lb][ub];

    ll x=0;

    if (lb == 0 && ub == 0)
    {
        arr.push_back(low);
        x=x|fun(low, high, pos + 1, lb, ub, arr, l, r,ndig,ans);
    }
    else if (lb == 1 && ub == 0)
    {
        for (ll j = max(low, dig1); j <= high; j++)
        {
            arr.push_back(j);
            x=x|fun(low, high, pos + 1, !(j > dig1), ub, arr, l, r,ndig,ans);
            arr.pop_back();
        }
    }
    else if (lb == 0 && ub == 1)
    {
        for (ll j = low; j <= min(high, dig2); j++)
        {
            arr.push_back(j);
            x=x|fun(low, high, pos + 1, lb, !(j < dig2), arr, l, r,ndig,ans);
            arr.pop_back();
        }
    }
    else
    {
        for (ll j = max(low, dig1); j <= min(high, dig2); j++)
        {
            arr.push_back(j);
            x=x|fun(low, high, pos + 1, !(j > dig1), !(j < dig2), arr, l, r,ndig,ans);
            arr.pop_back();
        }
    }
    return dp[low][high][pos][lb][ub]=x;
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    ll temp = l;
    ll ndig = 0;
    while (temp > 0)
    {
        temp /= 10;
        ndig++;
    }
    vector<ll>l1=intTOVect(l);
    vector<ll>r2=intTOVect(r);
    vector<ll>r1;
    if(r2.size()>l1.size())
    {
        for(ll j=0;j<l1.size();j++)
        {
            r1.push_back(9);
        }
    }
    else
    {
        r1=intTOVect(r);
    }

    vector<ll>ans;
    for (ll diff = 0; diff <= 9; diff++)
    {
        for (ll low = 0; low < 10; low++)
        {
            ll high = diff + low;
            if (high > 9)
                continue;
            vector<ll>res;
            ll x=fun(low,high,0,1,1,res,l1,r1,ndig,ans);
            if(x)
            {
            break;
            }
        }
    }
    for(auto it:ans)
    cout<<it;
    cout<<"\n";
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
        initdp();
        solve();
    }
    return 0;
}
