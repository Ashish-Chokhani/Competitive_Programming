#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename num_t>
struct segtree
{
    ll n, depth;
    vector<num_t> tree, lazy;

    void init(ll s, long long *arr)
    {
        n = s;
        tree = vector<num_t>(4 * s, 0);
        lazy = vector<num_t>(4 * s, 0);
        init(0, 0, n - 1, arr);
    }

    num_t init(ll i, ll l, ll r, long long *arr)
    {
        if (l == r)
            return tree[i] = arr[l];

        ll mid = (l + r) / 2;
        num_t a = init(2 * i + 1, l, mid, arr),
              b = init(2 * i + 2, mid + 1, r, arr);
        return tree[i] = a.op(b);
    }

    void update(ll l, ll r, num_t v)
    {
        if (l > r)
            return;
        update(0, 0, n - 1, l, r, v);
    }

    num_t update(ll i, ll tl, ll tr, ll ql, ll qr, num_t v)
    {
        eval_lazy(i, tl, tr);

        if (tl > tr || tr < ql || qr < tl)
            return tree[i];
        if (ql <= tl && tr <= qr)
        {
            lazy[i] = lazy[i].val + v.val;
            eval_lazy(i, tl, tr);
            return tree[i];
        }

        if (tl == tr)
            return tree[i];

        ll mid = (tl + tr) / 2;
        num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
              b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
        return tree[i] = a.op(b);
    }

    num_t query(ll l, ll r)
    {
        if (l > r)
            return num_t::null_v;
        return query(0, 0, n - 1, l, r);
    }

    num_t query(ll i, ll tl, ll tr, ll ql, ll qr)
    {
        eval_lazy(i, tl, tr);

        if (ql <= tl && tr <= qr)
            return tree[i];
        if (tl > tr || tr < ql || qr < tl)
            return num_t::null_v;

        ll mid = (tl + tr) / 2;
        num_t a = query(2 * i + 1, tl, mid, ql, qr),
              b = query(2 * i + 2, mid + 1, tr, ql, qr);
        return a.op(b);
    }

    void eval_lazy(ll i, ll l, ll r)
    {
        tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
        if (l != r)
        {
            lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
            lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
        }

        lazy[i] = num_t();
    }
};

struct max_t
{
    long long val;
    static const long long null_v = -9223372036854775807LL;

    max_t() : val(0) {}
    max_t(long long v) : val(v) {}

    max_t op(max_t &other)
    {
        return max_t(max(val, other.val));
    }

    max_t lazy_op(max_t &v, int size)
    {
        return max_t(val + v.val);
    }
};

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, pair<ll, ll>>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        arr[i].first = y;
        arr[i].second.first = x;
        arr[i].second.second = z;
    }
    sort(arr.begin(), arr.end());
    ll dp[n];
    memset(dp, 0, sizeof(dp));
    vector<ll>a(n),b(n),h(n);
    for(ll i=0;i<n;i++)
    {
        a[i]=arr[i].second.first;
        b[i]=arr[i].first;
        h[i]=arr[i].second.second;
    }
    dp[0]=h[0];
    segtree<max_t>Sg;
    Sg.init(n,dp);
    for(int i=1;i<n;i++)
    {
        ll index=upper_bound(b.begin(),b.end(),a[i])-b.begin();
        ll val=0;
        if(index<n && index<=i)
        {
            val=Sg.query(index,i).val;
        }
        dp[i]=h[i]+val;
        Sg.update(i,i,dp[i]);
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}