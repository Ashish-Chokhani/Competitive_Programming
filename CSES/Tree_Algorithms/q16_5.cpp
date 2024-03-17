#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
//const ll INF = 1e18;
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

template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s,num_t());
    lazy = vector<num_t>(4 * s,num_t());
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = num_t(arr[l],0);

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
    eval_lazy(i, tl, tr);
	
	if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i].val = lazy[i].val + tl-ql;
      lazy[i].freq=v.freq;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
	if (l > r) return num_t();
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t();

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  void eval_lazy(int i, int l, int r) {
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    int sz=r-l+1;
    int c=(sz+1)/2;
    if (l != r && lazy[i].freq) {
      lazy[i * 2 + 1].val = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 1].freq+=lazy[i].freq;
      lazy[i * 2 + 2].val = (lazy[i].val+c) + lazy[i * 2 + 2].val;
      lazy[i * 2 + 2].freq+=lazy[i].freq;
    }

    lazy[i] = num_t();
  }
  
  void Print(){
  	for(ll i=0;i<7;i++){
  		cout<<i<<" "<<tree[i].val<<" "<<tree[i].freq<<" "<<lazy[i].val<<" "<<lazy[i].freq<<endl;
  	}
  }
};

struct sum_t {
  long long val,freq;
  static const long long null_v = 0;

  sum_t(): val(0),freq(0) {}
  sum_t(long long v,long long f): val(v),freq(f) {}

  sum_t op(sum_t& other) {
    return sum_t(val+ other.val,0);
  }
  
  sum_t lazy_op(sum_t& v, int size) {
  	if(!v.freq) return sum_t(val,freq);
    return sum_t(val + v.val*v.freq*size + (size*(size+1)*v.freq)/2,0);
  }
};

void solve(){
	ll n,q;
	cin>>n>>q;
	long long arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	segtree<sum_t>Sg;
	Sg.init(n,arr);
	while(q--){
		ll type;
		cin>>type;
		if(type==1){
			ll a,b;
			cin>>a>>b;
			--a;--b;
			Sg.update(a,b,sum_t(1,1));
			//cout<<"After update:\n";
			//Sg.Print();
		}
		else{
			ll a,b;
			cin>>a>>b;
			--a;--b;
			cout<<Sg.query(a,b).val<<endl;
			//cout<<"After query:\n";
			//Sg.Print();
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