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
 
void solve(){
  ll n,m;
  cin>>n>>m;
  vector<pair<ll,ll>>adj[n+1],rev_adj[n+1];
  vector<pair<ll,pair<ll,ll>>>edges;
  for(ll i=0;i<m;i++){
    ll u,v,wt;
    cin>>u>>v>>wt;
    --u;--v;
    adj[u].push_back({v,wt});
    rev_adj[v].push_back({u,wt});
    edges.push_back({u,{v,wt}});
  }
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq_src,pq_dst;
  pq_src.push({0,0});
  pq_dst.push({0,n-1});
  vector<ll>dis_from_src(n,INF),dis_from_dst(n,INF),vis_from_src(n,0),vis_from_dst(n,0);
  dis_from_src[0]=dis_from_dst[n-1]=0;
  
  //distance[x][0] denotes minimum cost to reach x given coupon is not available
  //distance[x][1] denotes minimum cost to reach x given coupon is still available
  
  while(!pq_src.empty()){
    ll dist=pq_src.top().first;
    ll node=pq_src.top().second;
    pq_src.pop();
    if(vis_from_src[node]) continue;
    vis_from_src[node]=1;
    for(auto it:adj[node]){
      ll to=it.first;
      ll wt=it.second;
        if(dist+wt<dis_from_src[to]){
          dis_from_src[to]=dist+wt;
          pq_src.push({dis_from_src[to],to});
        }
    }
  }
  
  while(!pq_dst.empty()){
    ll dist=pq_dst.top().first;
    ll node=pq_dst.top().second;
    pq_dst.pop();
    if(vis_from_dst[node]) continue;
    vis_from_dst[node]=1;
    for(auto it:rev_adj[node]){
      ll to=it.first;
      ll wt=it.second;
        if(dist+wt<dis_from_dst[to]){
          dis_from_dst[to]=dist+wt;
          pq_dst.push({dis_from_dst[to],to});
        }
    }
  }
  
  ll ans=INF;
  for(auto it:edges){
    ll u=it.first;
    ll v=it.second.first;
    ll wt=it.second.second;
    ans=min(ans,dis_from_src[u]+wt/2+dis_from_dst[v]);
  }
  cout<<ans<<"\n";
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