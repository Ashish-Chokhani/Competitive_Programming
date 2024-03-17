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
// for erase use: st.erase(st.find_by_order(val);

bool DetectCycle(ll cur,vector<ll>&vis,vector<ll>*adj){
  vis[cur]=1;
  for(auto it:adj[cur]){
    if(vis[it]==1) return true;
    if(vis[it]==2) continue;
    if(DetectCycle(it,vis,adj)) return true;;
  }
  vis[cur]=2;
  return false;
}

void topoSort(ll cur,vector<ll>*adj,vector<ll>&vis,stack<ll>&ans){
  vis[cur]=1;
  for(auto it:adj[cur]){
    if(vis[it]) continue;
    topoSort(it,adj,vis,ans);
  }
  ans.push(cur);
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<ll>adj[n+1];
  for(ll i=0;i<m;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
  	adj[u].push_back(v);
  }
  vector<ll>vis(n,0);
  for(ll i=0;i<n;i++){
  	if(!vis[i]){
      if(DetectCycle(i,vis,adj)){
        cout<<"IMPOSSIBLE\n";
        return;
      }
    }
  }
  stack<ll>ans;
  vis.clear();
  vis.resize(n);
  fill(vis.begin(),vis.end(),0);
  for(ll i=0;i<n;i++){
    if(!vis[i]) topoSort(i,adj,vis,ans);
  }
  while(!ans.empty()){
    ll node=ans.top();
    ans.pop();
    cout<<node+1<<" ";
  }
  cout<<endl;
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