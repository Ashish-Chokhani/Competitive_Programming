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
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];

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
    //cout<<"ok "<<tree[4].val<<endl;
	
	if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      //cout<<"Haan "<<tl<<" "<<tr<<" "<<ql<<" "<<qr<<endl;
      lazy[i].val = lazy[i].val + v.val + v.setAll;
      lazy[i].isSetVal=v.isSetVal;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    //cout<<tl<<" "<<tr<<" "<<a.op(b).val<<endl;
    //if(tl==3) cout<<a.val<<" "<<b.val<<endl;
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
	if (l > r) return num_t::null_v;
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  void eval_lazy(int i, int l, int r) {
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      if(lazy[i].isSetVal){
	      lazy[i * 2 + 1].isSetVal = lazy[i * 2 + 2].isSetVal = 1;
	      lazy[i * 2 + 1].setAll = lazy[i * 2 + 2].setAll = lazy[i].setAll;
	      lazy[i * 2 + 1].val = lazy[i * 2 + 2].val = lazy[i].val;
      }
      else{
      	lazy[i * 2 + 1].val = lazy[i].val + lazy[i * 2 + 1].val;
      	lazy[i * 2 + 2].val = lazy[i].val + lazy[i * 2 + 2].val;
      }
    }

    lazy[i] = num_t();
  }
};

struct sum_t {
  long long val,setAll,isSetVal; 
  static const long long null_v = 0;

  sum_t(): val(0),setAll(0),isSetVal(0) {}
  sum_t(long long v): val(v) {}
  sum_t(long long v,long long x,long long bit): val(v),setAll(x),isSetVal(bit) {}

  sum_t op(sum_t& other) {
    return sum_t(val + other.val);
  }
  
  sum_t lazy_op(sum_t& v, int size) {
    if(v.isSetVal==0) return sum_t(val+v.val*size,0,0);
    return sum_t((v.setAll+v.val)*size,0,0); 
  }
};
 
 void solve(){
   ll n,q;
   cin>>n>>q;
   ll arr[n];
   for(ll i=0;i<n;i++){
   	cin>>arr[i];
   }
   segtree<sum_t>Sg;
   Sg.init(n,arr);
   while(q--){
   	ll type;
   	cin>>type;
   	if(type==1){
   		ll l,r,x;
   		cin>>l>>r>>x;
   		--l;--r;
   		sum_t new_val(x,0,0);
   		Sg.update(l,r,new_val);
   	}
   	else if(type==2){
   		ll l,r,x;
   		cin>>l>>r>>x;
   		--l;--r;
   		sum_t new_val(0,x,1);
   		Sg.update(l,r,new_val);
   	}
   	else{
   		ll l,r;
   		cin>>l>>r;
   		--l;--r;
   		cout<<Sg.query(l,r).val<<"\n";
   	}
   }
 } 
 
 int main()
 {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     
     // #ifndef ONLINE_JUDGE
     // freopen("input.txt","r",stdin);
     // freopen("output.txt","w",stdout);
     // freopen("error.txt","w",stderr);
     // #endif
     
     ll t;
     //cin >> t;
     t=1;
     while (t--)
     {
         solve();
     }
     return 0;
 }