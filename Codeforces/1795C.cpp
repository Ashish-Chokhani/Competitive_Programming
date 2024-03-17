#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename num_t> 
struct segtree {
  ll n, depth;
  vector<num_t> tree, lazy;

  void init(ll s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(ll i, ll l, ll r, long long* arr) {
    if (l == r) return tree[i] = arr[l];

    ll mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(ll l, ll r, num_t v) {
	if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(ll i, ll tl, ll tr, ll ql, ll qr, num_t v) {
    eval_lazy(i, tl, tr);
	
	if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    ll mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(ll l, ll r) {
	if (l > r) return num_t::null_v;
    return query(0, 0, n-1, l, r);
  }

  num_t query(ll i, ll tl, ll tr, ll ql, ll qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t::null_v;

    ll mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  void eval_lazy(ll i, ll l, ll r) {
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }

    lazy[i] = num_t();
  }
};

struct sum_t {
  long long val;
  static const long long null_v = 0;

  sum_t(): val(0) {}
  sum_t(long long v): val(v) {}

  sum_t op(sum_t& other) {
    return sum_t(val + other.val);
  }
  
  sum_t lazy_op(sum_t& v, ll size) {
    return sum_t(val + v.val * size);
  }
};

void solve()
{
    ll n;
    cin>>n;
    vector<ll>a(n),b(n),p(n,0);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>b[i];
    }
    p[0]=b[0];
    for(ll i=1;i<n;i++)
    {
        p[i]=b[i]+p[i-1];
    }
    vector<ll>s(n+1,0);
    ll freq[n];
    memset(freq,0,sizeof(freq));
    segtree<sum_t>Sg;
    Sg.init(n,freq);
    s[0]=min(a[0],b[0]);
    ll rem=a[0]-s[0];
    ll control=1;
    while(control<n && rem>0)
    {
        s[control]=min(rem,b[control]);
        rem-=s[control];
        control++;
    }
    for(ll i=1;i<n;i++)
    {
        ll key=p[i-1]+a[i];
        ll ind=lower_bound(p.begin(),p.end(),key)-p.begin();
        if(ind==n || p[ind]!=key)
        ind--;
        if(ind<i)
        ind=i-1;
        Sg.update(i,ind,1);
        ll rem=key-p[ind];
        s[ind+1]+=min(rem,b[ind+1]);
    }
    for(ll i=0;i<n;i++)
    {
        ll f=Sg.query(i,i).val;
        cout<<s[i]+(f*b[i])<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll  t;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}
