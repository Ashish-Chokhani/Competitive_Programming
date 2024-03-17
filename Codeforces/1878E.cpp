#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SGTree
{
    vector<ll> seg, lazy;

public:
    SGTree(ll n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

public:
    void build(ll ind, ll low, ll high, vector<ll> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] & seg[2 * ind + 2];
    }

public:
    void update(ll ind, ll low, ll high, ll l, ll r, ll val)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (high-low+1)*lazy[ind];

            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if (high < l || r < low)
            return;

        if (low >= l && high <= r)
        {
            seg[ind] += (high-low+1)*val;
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        ll mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    ll query(ll ind, ll low, ll high, ll l, ll r)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (high-low+1)*lazy[ind];

            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        
        if (high < l || r < low)
            return (1LL<<30)-1;

        if (low >= l && high <= r)
        {
            return seg[ind];
        }
        ll mid = (low + high) / 2;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        return left & right;
    }
};

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    SGTree Sg(n);
    Sg.build(0,0,n-1,arr);
    ll q;
    cin>>q;
    while(q--){
        ll l,k;
        cin>>l>>k;
        --l;
        ll low=l,high=n-1,ans=-2;
        while(low<=high){
            ll mid=(low+high)/2;
            if(Sg.query(0,0,n-1,l,mid)>=k){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        cout<<ans+1<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    ll cnt=0;
    while (t--)
    {
        solve();
    }
    return 0;
}