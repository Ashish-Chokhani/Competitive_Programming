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

bool isValid(ll j,ll i,vector<ll>&arr){
	return abs(arr[i]-j)<=1;
}

ll fun(ll i,ll last,vector<ll>&arr){
	if(i<0) return 1;
	if(last==0) return fun(i-1,)
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  
  // dp[i][j] number of valid arrays till index i given that last 
  // element placed is j
  
  vector<vector<ll>>dp(n+1,vector<ll>(m+2,0));
  // vector<ll>prev(m+2,1);
  // for(ll i=1;i<=n;i++){
  // 	vector<ll>cur(m+2,0);
  // 	for(ll j=0;j<=m;j++){
  // 		if(arr[i-1]==0){
  // 			cur[j]+=prev[j];
  // 			if(j-1>=0) cur[j]+=prev[j-1];
  // 			if(j+1<=m) cur[j]+=prev[j+1];
  // 		}
  // 		else{
  // 			if(isValid(j,i-1,arr) || i==n) cur[j]+=prev[arr[i-1]];
  // 		}
  // 	}
  // 	prev=cur;
  // }
  // cout<<prev[m]<<"\n";
  // for(ll i=0;i<=m;i++){
  // 	dp[0][i]=1;
  // }
  for(ll i=1;i<=m;i++){
  	if(arr[0]==0) dp[1][i]=m;
  	else dp[1][i]=1;
  }
  for(ll i=1;i<=n;i++){
  	for(ll j=1;j<=m;j++){
  		if(arr[i-1]==0){
  			dp[i][j]+=dp[i-1][j];
  			if(j-1>=1) dp[i][j]+=dp[i-1][j-1];
  			if(j+1<=m) dp[i][j]+=dp[i-1][j+1];
  		}
  		else{
  			if(isValid(j,i-1,arr) || i==n) dp[i][j]+=dp[i-1][arr[i-1]];
  		}
  	}
  }
  // debug(dp);
  cout<<dp[n][m]<<"\n";
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
    t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}