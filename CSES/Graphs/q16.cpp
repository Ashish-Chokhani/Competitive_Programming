#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e8;
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
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
  	adj[u].push_back({v,-1});
  }
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
  pq.push({0,0});
  vector<ll>distance(n,INF),parent(n,-1);
  distance[0]=0;
  while(!pq.empty()){
  	ll dist=pq.top().first;
  	ll node=pq.top().second;
  	pq.pop();
  	if(distance[node]<dist) continue;
  	for(auto it:adj[node]){
  		ll to=it.first;
  		ll wt=it.second;
  		if(dist+wt<distance[to]){
  			parent[to]=node;
  			distance[to]=dist+wt;
  			pq.push({distance[to],to});
  		}
  	}
  }
  if(distance[n-1]==INF){
  	cout<<"IMPOSSIBLE\n";
  	return;
  }
  vector<ll>ans;
  ll cur=n-1;
  while(cur!=0){
  	ans.push_back(cur);
  	cur=parent[cur];
  }
  ans.push_back(0);
  reverse(ans.begin(),ans.end());
  cout<<ans.size()<<endl;
  for(auto it:ans){
  	cout<<it+1<<" ";
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