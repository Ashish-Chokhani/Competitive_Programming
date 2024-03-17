#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SGTree
{
    vector<ll> seg, lazy;

public:
    void init(ll n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4* n + 1);
    }

public:
    void build(ll ind, ll low, ll high, vector<ll> &arr)
    {
        if (low == high)
        {
            seg[ind] = (1LL<< arr[low]);
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
    }

public:
    void update(ll ind, ll low, ll high, ll l, ll r, ll val)
    {
        if (lazy[ind] != 0)
        {
            seg[ind]  = lazy[ind];

            if (low != high)
            {
                lazy[2 * ind + 1]  = lazy[ind];
                lazy[2 * ind + 2]  = lazy[ind];
            }
            lazy[ind] = 0;
        }

        if (high < l || r < low)
            return;

        if (low >= l && high <= r)
        {
            seg[ind] = 1LL << val;
            if (low != high)
            {
                lazy[2 * ind + 1] = 1LL << val;
                lazy[2 * ind + 2] = 1LL << val;
            }
            return;
        }
        ll mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
    }
    ll query(ll ind, ll low, ll high, ll l, ll r)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] = lazy[ind];

            if (low != high)
            {
                lazy[2 * ind + 1] = lazy[ind];
                lazy[2 * ind + 2] = lazy[ind];
            }
            lazy[ind] = 0;
        }
        
        if (high < l || r < low)
            return 0;

        if (low >= l && high <= r)
        {
            return seg[ind];
        }
        ll mid = (low + high) / 2;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        return left | right;
    }
};

void DFS(ll cur,ll par,ll &cnt,vector<pair<ll,ll>>&range,vector<ll>*adj)
{
    range[cur].first=cnt;
    for(auto it:adj[cur])
    {
        if(it!=par)
        {
            cnt++;
            DFS(it,cur,cnt,range,adj);
        }
    }
    range[cur].second=cnt;
}

void solve()
{
    ll n,m;
    cin >> n >>m;
    SGTree Sg;
    vector<pair<ll,ll>>range(n);
    Sg.init(n);
    vector<ll>temp(n),color(n);
    for(ll i=0;i<n;i++)
    {
        cin>>temp[i];
        --temp[i];
    }
    vector<ll>adj[n];
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll cnt=0;
    DFS(0,-1,cnt,range,adj);
    for(ll i=0;i<n;i++)
    {
        color[range[i].first]=temp[i];
    }
    Sg.build(0,0,n-1,color);

    //cout<<__builtin_popcount(Sg.query(0,0,n-1,range[0].first,range[0].second))<<"\n";
    while(m--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll v, c;
            cin>>v>>c;
            --v;
            --c;
            Sg.update(0,0,n-1,range[v].first,range[v].second,c);
        }
        else
        {
            ll v;
            cin>>v;
            --v;
            ll val=Sg.query(0,0,n-1,range[v].first,range[v].second);
            cout<<__builtin_popcountll(val)<<"\n";
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
