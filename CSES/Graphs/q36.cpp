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

ll findFlow(ll s,ll t,vector<ll>*adj,vector<vector<ll>>&capacity,vector<ll>&parent){
	queue<pair<ll,ll>>q;
  
	for(ll i=0;i<(ll)parent.size();i++) parent[i]=-1;
	q.push({s,INF});
	parent[s]=-2;
	while(!q.empty()){
		ll cur=q.front().first;
		ll flow=q.front().second;
		q.pop();
		for(ll next:adj[cur]){
			if(parent[next]==-1 && capacity[cur][next]){
				parent[next]=cur;
				ll new_flow=min(flow,capacity[cur][next]);
				if(next==t) return new_flow;
				q.push({next,new_flow});
			}
		}
	}
	return 0;
}

ll calcMaxFlow(ll s,ll t,vector<ll>*adj,ll n,vector<vector<ll>>&capacity){
	ll flow=0,new_flow=0;
	vector<ll>parent(n,-1);
	while((new_flow=findFlow(s,t,adj,capacity,parent))){
		flow+=new_flow;
		ll cur=t;
		while(cur!=s){
			ll prev=parent[cur];
			capacity[prev][cur]-=new_flow;
			capacity[cur][prev]+=new_flow;
			cur=prev;
		}
	}
	return flow;
}

void DFS(ll cur,ll t,vector<ll>*graph,vector<ll>&vis,vector<vector<ll>>&capacity,vector<ll>&path,map<pair<ll,ll>,ll>&id){
  path.push_back(cur);
  if(cur==t) return;
  for(auto to:graph[cur]){
    if(!vis[id[{cur,to}]] && capacity[cur][to]==0){
      vis[id[{cur,to}]]=1;
      DFS(to,t,graph,vis,capacity,path,id);
      return;
    }
    
  }
}

void solve(){
  ll n,k;
  cin>>n>>k;
  vector<ll>adj[2*n+4];
  vector<ll>graph[2*n+4];
  vector<vector<ll>>capacity(2*n+4,vector<ll>(2*n+4,0));
  map<pair<ll,ll>,ll>isEdge,id;
  ll cur_id=1;
  for(ll i=0;i<k;i++){
  	ll u,v;
  	cin>>u>>v;
    graph[u].push_back(v);
  	adj[u].push_back(v);
  	adj[v].push_back(u);
    id[{u,v}]=cur_id++;
  	capacity[u][v]=1;
    isEdge[{u,v}]=1;
  }
  ll s=1,t=n;
  ll K=calcMaxFlow(s,t,adj,2*n+4,capacity);
  cout<<K<<endl;
  vector<vector<ll>>ans;
  vector<ll>vis(k+4,0),path;
  for(ll i=1;i<=K;i++){
    path.clear();
    DFS(1,t,graph,vis,capacity,path,id);
    ans.push_back(path);
  }
  for(auto it:ans){
    cout<<it.size()<<endl;
    for(auto elt:it) cout<<elt<<" ";
    cout<<endl;
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