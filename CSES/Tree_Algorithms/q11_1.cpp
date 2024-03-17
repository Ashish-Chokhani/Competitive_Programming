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

const ll max_N=2e5+2;
vector<ll>val,start,en;
vector<ll>adj[max_N+1];
ll tim;

struct Query{
  ll r,idx;
  bool operator<(Query other){
    return en[r]<en[other.r];
  }
};

void DFS(ll cur,ll par){
  start[cur]=tim;
	for(ll child:adj[cur]){
		if(child==par) continue;
		DFS(child,cur);
	}
  en[cur]=tim;
}

void solve(){
  ll n,q;
  cin>>n>>q;
  val.resize(n,0);
  start.resize(n,0);
  en.resize(n,0);
  tim=0;
  for(auto &a:val){
    cin>>a;
  }
  for(ll i=0;i<n-1;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  DFS(0,-1);
  vector<ll>queries;
  vector<ll>ans;
  ll max_sz=sqrt(q)+1;
  while(q--){
    ll type;
    cin>>type;
    if(type==1){
      ll s,x;
      cin>>s>>x;
      --s;
      ll cur_sz=queries.size();
      if(cur_sz<max_sz){
        //queries.push_back()
      }
    }
    else{
      ll s;
      cin>>s;
      --s;
      //Dont forget to revert back the changes made in original array
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