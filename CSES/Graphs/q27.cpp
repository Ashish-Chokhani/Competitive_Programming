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
// for erase use: st.erase(st.find_by_order(val);

void DFS(ll cur,vector<ll>*adj,vector<ll>&vis,stack<ll>&st){
	vis[cur]=1;
	for(auto it:adj[cur]){
		if(vis[it]) continue;
		DFS(it,adj,vis,st);
	}
	st.push(cur);
}

void DFS3(ll cur,vector<ll>*adj,vector<ll>&vis,ll &id,vector<ll>&ans){
	vis[cur]=1;
  ans[cur]=id;
	for(auto it:adj[cur]){
		if(vis[it]) continue;
		DFS3(it,adj,vis,id,ans);
	}
}

void topoSort(ll cur,vector<ll>*adj,vector<ll>&vis,stack<ll>&st){
  vis[cur]=1;
  for(auto it:adj[cur]){
    if(vis[it]) continue;
    topoSort(it,adj,vis,st);
  }
  st.push(cur);
}

void DFS4(ll cur,vector<ll>*adj,vector<ll>&vis,vector<ll>&dp,vector<ll>&coins){
  vis[cur]=1;
  dp[cur]=coins[cur];
  ll val=0;
  for(auto it:adj[cur]){
    if(!vis[it]) DFS4(it,adj,vis,dp,coins);
    val=max(val,dp[it]);
  }
  dp[cur]+=val;
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<ll>coins(n,0);
  for(auto &x:coins){
    cin>>x;
  }
  vector<ll>adj[n+1],adjT[n+1];
  vector<pair<ll,ll>>edges;
  for(ll i=0;i<m;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
    edges.push_back({u,v});
  	adj[u].push_back(v);
  	adjT[v].push_back(u);
  }
  vector<ll>vis(n,0);
  stack<ll>st;
  for(ll i=0;i<n;i++){
  	if(!vis[i]) DFS(i,adj,vis,st);
  }
  vis.clear();
  vis.assign(n,0);
  vector<ll>ans(n);
  ll id=-1,nhead=0;
  while(!st.empty()){
  	ll node=st.top();
  	st.pop();
  	if(vis[node]) continue;
    id++;
    nhead++;
  	DFS3(node,adjT,vis,id,ans);
  }
  vector<ll>condensed_adj[nhead+1];
  vector<ll>new_coins(nhead,0);
  for(ll i=0;i<n;i++){
    new_coins[ans[i]]+=coins[i];
  }
  map<pair<ll,ll>,ll>isEdgeAdded;
  for(auto it:edges){
    ll u=it.first;
    ll v=it.second;
    if(ans[u]==ans[v] || isEdgeAdded[{ans[u],ans[v]}]) continue; //belong to the same connected component
    condensed_adj[ans[u]].push_back(ans[v]);
    isEdgeAdded[{ans[u],ans[v]}]=1;
  }
  vis.clear();
  vis.assign(n,0);
  stack<ll>order;
  for(ll i=0;i<nhead;i++){
    if(!vis[i]) topoSort(i,condensed_adj,vis,order);
  }
  vis.clear();
  vis.assign(n,0);
  ll max_coins=0;
  vector<ll>dp(nhead,0);
  while(!order.empty()){
    ll node=order.top();
    order.pop();
    if(vis[node]) continue;
    DFS4(node,condensed_adj,vis,dp,new_coins);
  }
  for(auto &val:dp) max_coins=max(max_coins,val);
  cout<<max_coins<<endl;
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