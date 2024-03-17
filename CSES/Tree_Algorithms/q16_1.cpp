#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef  int ll;
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
    tree = vector<num_t>(4 * s, num_t(0, false));
    lazy = vector<num_t>(4 * s, num_t(0, false));
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = num_t(arr[l], false);

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
      lazy[i] = num_t(v.val,v.set_flag);  // Create a new num_t object
      eval_lazy(i, tl, tr);
      return tree[i];
    }

    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
      if (l > r) return num_t(); // Create a default-constructed num_t object
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
    if (l != r) {
      if(lazy[i].set_flag) lazy[i * 2 + 1] = lazy[i];
      if(lazy[i].set_flag) lazy[i * 2 + 2] = lazy[i];
    }

    lazy[i] = num_t();
  }
};

struct sum_t {
  long long val;
  bool set_flag;  // Flag to indicate if it's a set operation
  static const long long null_v = 0;

  sum_t(): val(0), set_flag(false) {}
  sum_t(long long v, bool set): val(v), set_flag(set) {}

  sum_t op(sum_t& other) {
    // Combine logic here if needed
    // In the context of sum, we may not need any special handling
    return sum_t(val + other.val, false);
  }
  
  sum_t lazy_op(sum_t& v, int size) {
    if (v.set_flag) {
      return sum_t(v.val*size, true);  // Set operation
    } else {
      return sum_t(val, false);
    }
  }
};

const ll maxN=2e5+2;
vector<ll>adj[maxN];
vector<ll>sub_sz(maxN,0);
vector<bool>vis(maxN,0);
long long cnt[maxN];
ll n,k1,k2,maxd;
long long ans=0;
segtree<sum_t>Sg;

void calcSubtreeSize(ll u,ll par){
	sub_sz[u]=1;
	for(ll child:adj[u]){
		if(!vis[child] && child!=par){
			calcSubtreeSize(child,u);
			sub_sz[u]+=sub_sz[child];
		}
	}
}

ll findCentroid(ll u,ll par,ll treeSize){
	for(ll child:adj[u]){
		if(!vis[child] && child!=par && sub_sz[child]>treeSize){
			return findCentroid(child,u,treeSize);
		}
	}
	return u;
}

void DFS(ll u,ll par,ll d,bool isCalculate){
	if(d>k2) return;
	if(isCalculate){
		ans+=Sg.query(max(0,k1-d),k2-d).val;
	}
	else{
		cnt[d]++;
		Sg.update(d,d,sum_t(cnt[d],true));
	}
	maxd=max(maxd,d);
	for(ll child:adj[u]){
    //if(u==2) cout<<"Children "<<child+1<<endl;
		if(!vis[child] && child!=par){
      DFS(child,u,d+1,isCalculate);
    }
	}
}

void centroid_decompose(ll u){
	calcSubtreeSize(u,-1);
	ll centroid=findCentroid(u,-1,sub_sz[u]>>1);
	vis[centroid]=1;
	maxd=0;
	cnt[0]=1;
	Sg.update(0,0,sum_t(1,true));
	
	for(ll child:adj[centroid]){
		if(!vis[child]){
			DFS(child,centroid,1,true);
			DFS(child,centroid,1,false);
		}
	}
  fill(cnt,cnt+maxd+1,0);
  Sg.update(0,maxd+1,sum_t(0,true));
	for(ll child:adj[centroid]){
		if(!vis[child]) centroid_decompose(child);
	}
}


void solve(){
	cin>>n>>k1>>k2;
	Sg.init(maxN,cnt);
	for(ll i=0;i<n-1;i++){
		ll u,v;
		cin>>u>>v;
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid_decompose(0);
	cout<<ans<<endl;
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
    memset(cnt,0,sizeof(cnt));
    while (t--)
    {
        solve();
    }
    return 0;
}