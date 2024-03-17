#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
//              tree_order_statistics_node_update>ordered_set;
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for set use less instead of less_equals
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

const ll maxN=3e5+2;
ll n,m,q;
ll positions[maxN],value[maxN];
set<ll>harbours;
ll arr1[maxN],arr2[maxN];

ll leftHarbour(ll cur){
	if(harbours.find(cur)!=harbours.end()) return cur;
  	auto it=harbours.lower_bound(cur);
  	--it;
  	return *it;
}
  
ll rightHarbour(ll cur){
	if(harbours.find(cur)!=harbours.end()) return cur;
  	auto it=harbours.lower_bound(cur+1);
  	return *it;
}

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

  num_t init(ll i, ll l,ll r, long long* arr) {
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
  
  void update1(ll l, ll r, num_t v) {
	if (l > r) return;
    update1(0, 0, n - 1, l, r, v);
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
  
  num_t update1(ll i, ll tl, ll tr, ll ql, ll qr, num_t v) {
    eval_lazy1(i, tl, tr);
	
	if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy1(i, tl, tr);
      return tree[i];
    }
    
    ll mid = (tl + tr) / 2;
    num_t a = update1(2 * i + 1, tl, mid, ql, qr, v),
          b = update1(2 * i + 2, mid + 1, tr, ql, qr, v);
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
  
  num_t query1(ll l, ll r) {
	if (l > r) return num_t::null_v;
    return query1(0, 0, n-1, l, r);
  }

  num_t query1(ll i, ll tl, ll tr, ll ql, ll qr) {
    eval_lazy1(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t::null_v;

    ll mid = (tl + tr) / 2;
    num_t a = query1(2 * i + 1, tl, mid, ql, qr),
          b = query1(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  void eval_lazy(ll i, ll l, ll r) {
    tree[i] = tree[i].lazy_op(lazy[i],(r-l+1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }

    lazy[i] = num_t();
  }
  
  void eval_lazy1(ll i, ll l, ll r) {
    tree[i] = tree[i].lazy_op1(lazy[i],l,r);
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
  
  sum_t lazy_op1(sum_t& v, ll tl,ll tr) {
  	ll size=tr-tl+1;
  	ll temp=(v.val * (size*(tl+tr)))/2;
  	ll new_val=val + temp;
    return sum_t(new_val);
  }
};

void solve(){
  cin>>n>>m>>q;
  memset(arr1,0,sizeof(arr1));
  memset(arr2,0,sizeof(arr2));
  memset(positions,0,sizeof(positions));
  memset(value,0,sizeof(value));
  harbours.insert(0);
  harbours.insert(n-1);
  for(ll i=0;i<m;i++){
  	cin>>positions[i];
  	--positions[i];
  	harbours.insert(positions[i]);
  }
  for(ll i=0;i<m;i++){
  	cin>>value[positions[i]];
  }
  for(ll i=0;i<n;i++){
  	arr1[i]=value[leftHarbour(i)]*rightHarbour(i);
  	arr2[i]=value[leftHarbour(i)]*i;
  }
  segtree<sum_t>Sg[2];
  Sg[0].init(maxN,arr1);
  Sg[1].init(maxN,arr2);
  while(q--){
  	ll type;
  	cin>>type;
  	if(type==1){
  		ll pos,v;
  		cin>>pos>>v;
  		--pos;
  		ll prev_right=rightHarbour(pos);
  		ll prev_left=leftHarbour(pos);
  		harbours.insert(pos);
  		value[pos]=v;
  		ll new_right=rightHarbour(pos);
  		ll new_left=leftHarbour(pos);
  		//To Do: Check for pos-1 or pos
  		//TO DO: check i or i+1
  		Sg[0].update(prev_left+1,pos-1,(new_right-prev_right)*value[prev_left]);
  		ll prev_val=Sg[0].query(pos,pos).val;
  		Sg[0].update(pos,pos,(value[pos]*pos)-prev_val);
  		Sg[0].update(pos+1,prev_right,(v-value[prev_left])*prev_right);
  		Sg[1].update1(pos,prev_right,(v-value[prev_left]));
  	}
  	else{
  		ll l,r;
  		cin>>l>>r;
  		--l;--r;
  		ll val1=Sg[0].query(l,r).val;
  		ll val2=Sg[1].query1(l,r).val;
  		cout<<val1-val2<<endl;
  	}
  }
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("error.txt","w",stderr);
    //#endif
    
    ll t;
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}