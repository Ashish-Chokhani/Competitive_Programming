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
  vector<pair<ll,ll>>adj[n+1];
  for(ll i=0;i<m;i++){
  	ll u,v,wt;
  	cin>>u>>v>>wt;
  	--u;--v;
  	adj[u].push_back({v,wt});
  }
  priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;
  pq.push({1,{0,0}});
  vector<vector<ll>>distance(n,vector<ll>(2,INF));
  distance[0][0]=distance[0][1]=0;
  
  //distance[x][0] denotes minimum cost to reach x given coupon is not available
  //distance[x][1] denotes minimum cost to reach x given coupon is still available
  
  while(!pq.empty()){
  	bool isCouponAvailable=(pq.top().first)==1;
  	ll dist=pq.top().second.first;
  	ll node=pq.top().second.second;
  	pq.pop();
  	for(auto it:adj[node]){
  		ll to=it.first;
  		ll wt=it.second;
  		if(isCouponAvailable){
  			if(dist+wt<distance[to][1]){
  				distance[to][1]=dist+wt;
  				pq.push({1,{distance[to][1],to}});
  			}
  			if(dist+wt/2<distance[to][0]){
  				distance[to][0]=dist+wt/2;
  				pq.push({0,{distance[to][0],to}});
  			}
  		}
  		else{
  			if(dist+wt<distance[to][0]){
  				distance[to][0]=dist+wt;
  				pq.push({0,{distance[to][0],to}});
  			}
  		}
  	}
  }
  cout<<distance[n-1][0]<<"\n";
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