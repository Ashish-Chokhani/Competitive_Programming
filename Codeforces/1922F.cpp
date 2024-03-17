#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1000000000000;
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
  ll n,x;
  cin>>n>>x;
  ll arr[n];
  map<ll,vector<ll>>where;
  for(ll i=0;i<n;i++){
  	cin>>arr[i];
  	where[arr[i]].push_back(i);
  }
  ll dp[n+1][n+1][x+1];
  for(ll i=0;i<=n;i++){
  	for(ll j=0;j<=n;j++){
  		for(ll k=0;k<=x;k++){
  			dp[i][j][k]=INF;
  		    if(j<i || i==n || j==n) dp[i][j][k]=0;
  		}
  	}
  }
  auto isPresent=[&](ll i,ll j,ll cur){
  	if(j<i) return false;
  	ll ind=lower_bound(where[cur].begin(),where[cur].end(),i)-where[cur].begin();
  	ll sz=where[cur].size();
  	if(ind==sz) return false;
  	return where[cur][ind]<=j;
  };
  // Modify inf and k
  for(ll i=n-1;i>=0;i--){
  	for(ll j=n-1;j>=0;j--){
  		if(j<i) continue;
  		for(ll k=1;k<=x;k++){
  			//Start a new Segment or continue the old one
  			if(i==j){
  				if(arr[j]==k) dp[i][j][k]=min(dp[i][j][k],dp[i+1][j+1][k]);
  				else{
  					dp[i][j][k]=min(dp[i][j][k],1+dp[i][j+1][k]);
  					dp[i][j][k]=min(dp[i][j][k],1+dp[i+1][j+1][k]);
  				}
  			}
  			else{
  				if(arr[j]!=k) dp[i][j][k]=min(dp[i][j][k],dp[i][j+1][k]);
  			    dp[i][j][k]=min(dp[i][j][k],dp[j+1][j+1][k]);
  			}
  		}
  	}
  }
  ll ans=1e12;
  for(ll i=1;i<=x;i++){
  	ans=min(ans,dp[0][0][i]);
  }
  // for(ll i=0;i<=n;i++){
  // 	for(ll j=0;j<=n;j++){
  // 		cout<<dp[i][j][1]<<" ";
  // 	}
  // 	cout<<endl;
  // }
  cout<<ans<<endl;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}