#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SGTree1
{
    vector<ll> seg1, lazy1;

public:
    SGTree1(ll n)
    {
        seg1.resize(4 * n + 1);
        lazy1.resize(4 * n + 1);
    }

public:
    void build(ll ind, ll low, ll high, vector<ll> &arr)
    {
        if (low == high)
        {
            seg1[ind] = arr[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg1[ind] = min(seg1[2 * ind + 1],seg1[2 * ind + 2]);
    }

public:
    void update(ll ind, ll low, ll high, ll l, ll r, ll val)
    {
        if (lazy1[ind] != 0)
        {
            seg1[ind] = lazy1[ind];

            if (low != high)
            {
                lazy1[2 * ind + 1] = lazy1[ind];
                lazy1[2 * ind + 2] = lazy1[ind];
            }
            lazy1[ind] = 0;
        }

        if (high < l || r < low)
            return;

        if (low >= l && high <= r)
        {
            seg1[ind] = val;
            if (low != high)
            {
                lazy1[2 * ind + 1] = val;
                lazy1[2 * ind + 2] = val;
            }
            return;
        }
        ll mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        seg1[ind] = min(seg1[2 * ind + 1],seg1[2 * ind + 2]);
    }
    ll query(ll ind, ll low, ll high, ll l, ll r)
    {
        if (lazy1[ind] != 0)
        {
            seg1[ind] = lazy1[ind];

            if (low != high)
            {
                lazy1[2 * ind + 1] = lazy1[ind];
                lazy1[2 * ind + 2] = lazy1[ind];
            }
            lazy1[ind] = 0;
        }
        
        if (high < l || r < low)
            return 1e9;

        if (low >= l && high <= r)
        {
            return seg1[ind];
        }
        ll mid = (low + high) / 2;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left,right);
    }
};

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n),minis(n,1e8),pre(n,0);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0)
        {
            pre[i]=arr[i];
        }
        else
        {
            pre[i]=pre[i-1]+arr[i];
        }
    }
    minis[0]=0;
    SGTree1 Sg1(n);
    Sg1.build(0,0,n-1,minis);
    vector<ll>ans;
    ans.push_back(0);
    for(ll i=1;i<n;i++)
    {
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        ll mini=Sg1.query(0,0,n-1,l,r);
        ans.push_back(pre[i]+mini);
        ll val=ans[ans.size()-1];
        Sg1.update(0,0,n-1,i,i,val-pre[i-1]);
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main()
{
    solve();
    return 0;
}
