#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
template<class T>void print(T x)
{
  cerr << x;
}
template<class T, class V>
         void print(pair<T , V> x)
{
  print(x.first); 
  cerr << ':';
  print(x.second);
}
template<class T>
         void print(vector<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(set<T,
                    greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(multiset<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(multiset<T, 
                    greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(unordered_set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T, class V>
         void print(vector<pair<T, V>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x.first);
    cerr << ":"; 
    print(x.second);
    cerr << ' ';
  }
  cerr << ']';
}
template <class T, class V> 
          void print(map <T, V> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template <class T, class V> 
          void print(unordered_map <T, V> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template <class T> 
          void print(vector<vector<T>> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template<class T>
         void print(stack<T> &a)
{
  cerr << '[' << ' ';
  stack<T>temp=a;
  while(!temp.empty())
  {
    auto val=temp.top();
    temp.pop();
    print(val); 
    cerr << " ";
  }
  cerr << ']';
}

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
	
	if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
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

void solve(){
	ll n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	set<ll>bad_positions;
	for(ll i=0;i<n;i++){
		if(i>=1 && s[i]==s[i-1]) bad_positions.insert(i);
		if(i<n-1 && s[i]==s[i+1]) bad_positions.insert(i);
	}
	ll arr[n];
	memset(arr,0,sizeof(arr));
	segtree<sum_t>Sg;
	Sg.init(n,arr);
	auto isGoodPos=[&](ll pos,ll pos_l,ll pos_r)->bool{
		return pos!=pos_l && pos!=pos_r;
	};
	while(q--){
		ll type;
		cin>>type;
		ll l,r;
		cin>>l>>r;
		--l;--r;
		if(type==1){
			Sg.update(l,r,1);
			ll parity_l=(Sg.query(l,l).val & 1)^(s[l]-'0');
			ll parity_r=(Sg.query(r,r).val & 1)^(s[r]-'0');
			ll parity_l1=parity_l^1; //l-1
			ll parity_r1=parity_r^1; //r+1
			ll parity_l3=parity_l^1; //l+1
			ll parity_r3=parity_r^1; //r-1
			ll parity_l2=parity_l1^1; //l-2
			ll parity_r2=parity_r1^1; //r+2
			if(l>=1) parity_l1=(Sg.query(l-1,l-1).val & 1)^(s[l-1]-'0');
			if(r<n-1) parity_r1=(Sg.query(r+1,r+1).val & 1)^(s[r+1]-'0');
			if(l>=2) parity_l2=(Sg.query(l-2,l-2).val & 1)^(s[l-2]-'0');
			if(r<n-2) parity_r2=(Sg.query(r+2,r+2).val & 1)^(s[r+2]-'0');
			if(l<n-1) parity_l3=(Sg.query(l+1,l+1).val & 1)^(s[l+1]-'0');
			if(r>=1) parity_r3=(Sg.query(r-1,r-1).val & 1)^(s[r-1]-'0');
			
			if(isGoodPos(parity_l,parity_l1,parity_l3)) bad_positions.erase(l);
			else bad_positions.insert(l);
			
			if(isGoodPos(parity_r,parity_r3,parity_r1)) bad_positions.erase(r);
			else bad_positions.insert(r);
			
			if(l>=1 && isGoodPos(parity_l1,parity_l2,parity_l)) bad_positions.erase(l-1);
			else if(l>=1) bad_positions.insert(l-1);
			
			if(r<n-1 && isGoodPos(parity_r1,parity_r,parity_r2)) bad_positions.erase(r+1);
			else if(r<n-1) bad_positions.insert(r+1);
			
		}
		else{
			ll parity_l=(Sg.query(l,l).val & 1)^(s[l]-'0');
			ll parity_r=(Sg.query(r,r).val & 1)^(s[r]-'0');
			ll parity_l1=parity_l^1; //l-1
			ll parity_r1=parity_r^1; //r+1
			ll parity_l3=parity_l^1; //l+1
			ll parity_r3=parity_r^1; //r-1
			if(l<r-1) parity_l3=(Sg.query(l+1,l+1).val & 1)^(s[l+1]-'0');
			if(r>=l+1) parity_r3=(Sg.query(r-1,r-1).val & 1)^(s[r-1]-'0');
			
			if(!isGoodPos(parity_l,parity_l1,parity_l3)){
				cout<<"No\n";
				continue;
			}
			
			if(!isGoodPos(parity_r,parity_r3,parity_r1)){
				cout<<"No\n";
				continue;
			}
			
			auto it=bad_positions.lower_bound(l+1);
			if(it==bad_positions.end() || *it>r-1) cout<<"Yes\n";
			else cout<<"No\n"<<endl;
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