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

const ll maxN=2e5+2;
vector<ll>parentT(maxN,0);
vector<ll>adj[maxN],adjT[maxN],graph[maxN];
vector<ll>cyclicNodes[maxN];
vector<bool>isCyclicNode(maxN,false);
vector<ll>vis(maxN,0),componentId(maxN);
unordered_map<ll,ll>where[maxN];
ll compId=0,timer=0;
vector<vector<ll>>up(maxN,vector<ll>(19));
vector<ll>tin(maxN,0),tout(maxN,0);


class TreeAncestor{
	unordered_map<ll,ll>cur_par,depth;
	ll LOG,max_depth;
public:
	void init(ll root){
		vector<ll>levelOrder;
		queue<pair<ll,ll>>q;
		q.push({root,root});
		while(!q.empty()){
			ll node=q.front().first;
			ll par=q.front().second;
			cur_par[node]=par;
			q.pop();
			levelOrder.push_back(node);
			for(ll child:adjT[node]){
				if(child!=par && !isCyclicNode[child]){
					q.push({child,node});
				}
			}
		}
		DFS2(root,0);
		LOG=18;
		for(ll v:levelOrder){
			up[v][0]=cur_par[v];
			if(v!=root) depth[v]=1+depth[cur_par[v]];
			for(ll j=1;j<=LOG;j++){
				up[v][j]=up[up[v][j-1]][j-1];
			}
		}		
	}
	ll findDepth(ll x){
		return depth[x];
	}
	
	void DFS2(ll cur,ll par){
		tin[cur]=timer++;
		for(ll child:adjT[cur]){
			if(child!=par && !isCyclicNode[child]){
				DFS2(child,cur);
			}
		}
		tout[cur]=timer++;
	}
	
	ll findKthAncestor(ll v,ll k){
		for(ll j=0;j<=LOG;j++){
			if(k&(1LL<<j)){
				v=up[v][j];
			}
		}
		return v;
	}
	
	bool isAncestor(ll b,ll a){
		return (tin[b]<tin[a] && tout[b]>tout[a]);
	}
};

void AssignComponentId(ll cur){
	vis[cur]=1;
	componentId[cur]=compId;
	for(ll child:graph[cur]){
		if(!vis[child]) AssignComponentId(child);
	}
}

void DFS(ll cur,ll par){
	vis[cur]=1;
	parentT[cur]=par;
	for(ll child:adj[cur]){
		if(vis[child]==2) continue;
		if(!vis[child]) DFS(child,cur);
		else{
			ll now=cur;
			while(now!=child){
				cyclicNodes[componentId[now]].push_back(now);
				isCyclicNode[now]=true;
				now=parentT[now];
			}
			cyclicNodes[componentId[now]].push_back(child);
			reverse(cyclicNodes[componentId[now]].begin(), cyclicNodes[componentId[now]].end());
			for(ll i=0;i<(ll)cyclicNodes[componentId[now]].size();i++){
				where[componentId[now]][cyclicNodes[componentId[now]][i]]=i;
			}
			isCyclicNode[child]=true;
		}
	}
	vis[cur]=2;
}

ll findDistance(ll a,ll b){
	ll cId_a=componentId[a];
	ll cId_b=componentId[b];
	ll pos1=where[cId_a][a];
	ll pos2=where[cId_b][b];
	ll cyclic_size=cyclicNodes[cId_a].size();
	if(pos1<=pos2) return pos2-pos1;
	return pos2+cyclic_size-pos1;
}

void solve(){
  ll n,q;
  cin>>n>>q;
  for(ll i=1;i<=n;i++){
  	ll v;
  	cin>>v;
  	adj[i].push_back(v);
  	adjT[v].push_back(i);
  	graph[i].push_back(v);
  	graph[v].push_back(i);
  }
  for(ll i=1;i<=n;i++){
  	if(!vis[i]){
  		AssignComponentId(i);
  		compId++;
  	}
  }
  vis.clear();
  vis.assign(maxN,0);
  for(ll i=1;i<=n;i++){
  	if(!vis[i]){
  		DFS(i,0);
  	}
  }
  //Initialize class for different roots
  TreeAncestor Tree[compId];
  for(ll i=0;i<compId;i++){
  	for(ll root:cyclicNodes[i]){
  		Tree[i].init(root);
  	}
  }
  while(q--){
  	ll a,b;
  	cin>>a>>b;
  	if(a==b){
  		cout<<"0\n";
  		continue;
  	}
  	if(componentId[a]!=componentId[b]){
  		cout<<"-1\n";
  		continue;
  	}
  	ll cId_a=componentId[a];
  	ll cId_b=componentId[b];
  	ll dep_a=Tree[cId_a].findDepth(a);
  	ll dep_b=Tree[cId_b].findDepth(b);
  	ll root_a=Tree[cId_a].findKthAncestor(a,dep_a);
  	ll root_b=Tree[cId_b].findKthAncestor(b,dep_b);
  	if((!isCyclicNode[a] && !isCyclicNode[b] && root_a!=root_b) || (isCyclicNode[a] && !isCyclicNode[b])){
  		cout<<"-1\n";
  		continue;
  	}  	
  	//Same cyclic: just find shortest distance between a and b
  	// Cycle and Tree: First move to root using root and then similarly fing shortest distance between a and b
  	if((isCyclicNode[a] && isCyclicNode[b]) || (!isCyclicNode[a] && isCyclicNode[b]))
  	cout<<dep_a+findDistance(root_a,b)<<endl;
    //Same Tree: b has to be an ancestor of a
  	else if(!isCyclicNode[a] && !isCyclicNode[b]){
  		   //Check b is an ancestor of a
  		if(!Tree[cId_a].isAncestor(b,a)){
  			cout<<"-1\n";
  			continue;
  		}
  		else{
  		     cout<<dep_a-dep_b<<endl;	
  		}
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