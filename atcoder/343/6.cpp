#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>ordered_set;
//using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for set use less instead of less_equals
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s,num_t(0,0));
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r){
    	tree[i].val1 = arr[l];
    	return tree[i];
    }

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
	if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
	if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      return tree[i]=num_t(v.val1,v.val2);
    }
    
    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
	if (l > r) return num_t(0,0);
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t(0,0);

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }
};

struct max_t {
  long long val1,val2;

  max_t(): val1(0),val2(0) {}
  max_t(long long v1,long long v2): val1(v1),val2(v2) {}

  max_t op(max_t& other) {
  	ll a1=max(val1, other.val1);
  	ll a2=0;
  	set<ll,greater<ll>>st;
  	st.insert(val1);
  	st.insert(val2);
  	st.insert(other.val1);
  	st.insert(other.val2);
  	if(st.size()>1) a2=*(++st.begin());
    return max_t(a1,a2);
  }
};

//Dont make mistake of +=val

void solve(){
  ll n,q;
  cin>>n>>q;
  ll arr[n];
  map<ll,ordered_set>where;
  for(ll i=0;i<n;i++){
  	cin>>arr[i];
  	where[arr[i]].insert(i);
  }
  segtree<max_t>Sg;
  Sg.init(n,arr);
  while(q--){
  	ll type;
  	cin>>type;
  	if(type==1){
  		ll p,x;
  		cin>>p>>x;
  		--p;
  		ll prev_val=arr[p];
  		arr[p]=x;
  		Sg.update(p,p,max_t(x,0));
  		where[prev_val].erase(where[prev_val].find_by_order(where[prev_val].order_of_key(p)));
  		where[x].insert(p);
  	}
  	else{
  		//answer a query
  		ll l,r;
  		cin>>l>>r;
  		--l;--r;
  		ll second_max=Sg.query(l,r).val2;
  		if(second_max==0){
  			cout<<"0\n";
  			continue;
  		}
  		ll c1=where[second_max].order_of_key(r+1);
  		ll c2=where[second_max].order_of_key(l);
  		cout<<c1-c2<<endl;
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