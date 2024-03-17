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
  
  sum_t lazy_op(sum_t& v, int size) {
    return sum_t(val + v.val * size);
  }
};

void solve()
{
    ll n,m,q;
    cin>>n>>m>>q;
    string s;
    cin>>s;
    ll arr[n];
    for(int i=0;i<n;i++){
        arr[i]=s[i]=='1';
    }
    ll c=0,sz=0;
    vector<ll>priorities(n,-1);
    vector<pair<ll,ll>>range(m);
    set<ll>st;
    for(ll i=0;i<n;i++){
        st.insert(i);
    }
    for(ll i=0;i<m;i++){
        cin>>range[i].first>>range[i].second;
        --range[i].first;
        --range[i].second;
        while(1){
            auto it=st.lower_bound(range[i].first);
            if(it==st.end() || *it>range[i].second) break;
            ll val=*it;
            st.erase(it);
            priorities[val]=c++;
            sz++;
        }
    }
    ll b[sz];
    for(ll i=0;i<n;i++){
        if(priorities[i]!=-1) b[priorities[i]]=s[i]-'0';
    }
    segtree<sum_t>Sg1,Sg2;
    Sg1.init(n,arr);
    Sg2.init(n,b);
    while(q--){
        ll x;
        cin>>x;
        --x;
        arr[x]=!arr[x];
        Sg1.update(x,x,arr[x]==0?-1LL:1LL);
        ll cnt1s=Sg1.query(0,n-1).val;
        if(priorities[x]!=-1){
            Sg2.update(priorities[x],priorities[x],arr[x]==0?-1LL:1LL);
        }
        ll unique1s=0;
        if(cnt1s>=1) unique1s=Sg2.query(0,min(sz-1,cnt1s-1)).val;
        cout<<max(0LL,min(sz,cnt1s)-unique1s)<<"\n";
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