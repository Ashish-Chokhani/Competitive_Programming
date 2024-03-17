#include<bits/stdc++.h>
using namespace std;

typedef long long ll; 

template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, num_t(0, false,0));
    lazy = vector<num_t>(4 * s, num_t(0, false,0));
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = num_t(arr[l], false,0);

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
      lazy[i] = num_t(v.val,v.set_flag,v.increment);  // Create a new num_t object
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
      else lazy[i * 2 + 1].increment+=lazy[i].increment;
      if(lazy[i].set_flag) lazy[i * 2 + 2] = lazy[i];
      else lazy[i * 2 + 2].increment+=lazy[i].increment;
    }

    lazy[i] = num_t();
  }
  
};

struct sum_t {
  long long val;
  bool set_flag;  // Flag to indicate if it's a set operation
  long long increment;
  static const long long null_v = 0;

  sum_t(): val(0),set_flag(false),increment(0) {}
  sum_t(long long v, bool set, long long i): val(v), set_flag(set),increment(i) {}

  sum_t op(sum_t& other) {
    // Combine logic here if needed
    // In the context of sum, we may not need any special handling
    return sum_t(val + other.val, false,0);
  }
  
  sum_t lazy_op(sum_t& v, int size) {
    if (v.set_flag) {
      return sum_t((v.val+v.increment)*size, true,0);  // Set operation
    } else {
      return sum_t(val+v.increment*size, false,0);
    }
  }
};

int main() {
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
      ll a,b,x;
      cin>>a>>b>>x;
      --a;--b;
      Sg.update(a,b,sum_t(0,false,x));
    }
    else if(type==2){
      ll a,b,x;
      cin>>a>>b>>x;
      --a;--b;
      Sg.update(a,b,sum_t(x,true,0));
    }
    else{
      ll a,b;
      cin>>a>>b;
      --a;--b;
      cout<<Sg.query(a,b).val<<endl;
    }
  }
  return 0;
}
