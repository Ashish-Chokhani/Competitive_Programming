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
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

void solve(){
  ll n,k;
  cin>>n>>k;
  vector<ll>adj[n];
  vector<ll>degree(n,0);
  for(ll i=0;i<n-1;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;
  	--v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  	degree[u]++;
  	degree[v]++;
  }
  queue<ll>q;
  vector<ll>vis(n,0);
  for(ll i=0;i<n;i++){
  	if(degree[i]==1){
  		q.push(i);
  		vis[i]=1;
  	}
  }
  ll centre=-1;
  if(q.size()<3){
  	cout<<"No\n";
  	return;
  }
  while(!q.empty()){
  	if(q.size()==1){
  		centre=q.front();
  	}
  	ll sz=q.size();
  	for(ll i=0;i<sz;i++){
  		ll node=q.front();
	  	q.pop();
	  	for(ll v:adj[node]){
	  		if(!vis[v]){
	  			q.push(v);
	  			vis[v]=1;
	  		}
	  	}
  	}
  }
  if(centre==-1){
  	cout<<"No\n";
  	return;
  }
  q.push(centre);
  vector<ll>vis1(n,0);
  vis1[centre]=1;
  ll cnt=0;
  while(!q.empty()){
  	cnt++;
  	ll sz=q.size();
  	for(ll i=0;i<sz;i++){
  		ll node=q.front();
	  	q.pop();
	  	ll nchild=0;
	  	for(auto it:adj[node]){
	  		if(!vis1[it]){
	  			nchild++;
	  			q.push(it);
	  			vis1[it]=1;
	  		}
	  	}
	  	if(nchild<3 && degree[node]!=1){
	  		cout<<"No\n";
	  		return;
	  	}
  	}
  }
  if(cnt!=k+1) cout<<"No\n";
  else cout<<"Yes\n";
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