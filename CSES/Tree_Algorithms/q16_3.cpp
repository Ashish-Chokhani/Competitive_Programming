#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef int ll;
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


int n, k1, k2;
vector<int> graph[200001];
int subtree[200001];
segtree<sum_t>Sg;
long long ans = 0;
long long int cnt[200001];
int mx_depth;
bool processed[200001];

int get_subtree_sizes(int node, int parent = -1) {
	subtree[node] = 1;
	for (int i : graph[node])
		if (!processed[i] && i != parent)
			subtree[node] += get_subtree_sizes(i, node);
	return subtree[node];
}

int get_centroid(int desired, int node, int parent = -1) {
	for (int i : graph[node])
		if (!processed[i] && i != parent && subtree[i] > desired)
			return get_centroid(desired, i, node);
	return node;
}

void get_cnt(int node, int parent, bool filling, int depth = 1) {
	if (depth > k2) return;
	mx_depth = max(mx_depth, depth);
	if (filling){
		cnt[depth]++;
		Sg.update(depth,depth,sum_t(cnt[depth],true));
	}
	else ans += Sg.query(max(0,k1-depth),k2-depth).val;
	for (int i : graph[node])
		if (!processed[i] && i != parent) get_cnt(i, node, filling, depth + 1);
}

void centroid_decomp(int node = 0) {
	int centroid = get_centroid(get_subtree_sizes(node) >> 1, node);
	processed[centroid] = true;
	mx_depth = 0;
	cnt[0]=1;
	Sg.update(0,0,sum_t(1,true));
	for (int i : graph[centroid])
		if (!processed[i]) {
			get_cnt(i, centroid, false);
			get_cnt(i, centroid, true);
		}
	fill(cnt + 1, cnt + mx_depth + 1, 0);
	Sg.update(0,mx_depth + 1,sum_t(0,true));
	for (int i : graph[centroid])
		if (!processed[i]) centroid_decomp(i);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k1 >> k2;
	Sg.init(200001,cnt);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		--u;--v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	centroid_decomp();
	cout << ans;
	return 0;
}