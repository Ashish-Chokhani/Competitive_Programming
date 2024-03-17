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
 
void DFS1(ll cur,ll par,vector<ll>*adj,vector<ll>&in,vector<ll>&out,vector<ll>&parent){
  parent[cur]=par;
  for(auto child:adj[cur]){
    if(child==par) continue;
    DFS1(child,cur,adj,in,out,parent);
    in[cur]=max(in[cur],1+in[child]);
  }
}
 
void DFS2(ll cur,ll par,vector<ll>*adj,vector<ll>&in,vector<ll>&out,vector<ll>&parent){
  if(par!=-1){
    for(auto child:adj[par]){
      if(child==cur || child==parent[par]) continue;
      out[cur]=max(out[cur],2+in[child]);
    } 
    out[cur]=max(out[cur],1+out[par]);
  }
  for(auto child:adj[cur]){
    if(child==par) continue;
    DFS2(child,cur,adj,in,out,parent);
  }
}
 
 
void solve(){
  ll n;
  cin>>n;
  vector<ll>adj[n];
  vector<ll>in(n,0),out(n,0),parent(n,0);
  for(ll i=0;i<n-1;i++){
    ll u,v;
    cin>>u>>v;
    --v;--u;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS1(0,-1,adj,in,out,parent);
  DFS2(0,-1,adj,in,out,parent);
  for(ll i=0;i<n;i++){
    cout<<max(in[i],out[i])<<" ";
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