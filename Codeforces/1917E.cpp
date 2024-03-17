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
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

ll n,k;

void printGrid(vector<vector<ll>>&ans){
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			cout<<ans[i][j]<<" \n"[j==n-1];
		}
	}
}

void solve(){
  cin>>n>>k;
  vector<vector<ll>>ans(n,vector<ll>(n,0));
  if(k&1){
  	cout<<"No\n";
  	return;
  }
  if(k==n){
  	cout<<"Yes\n";
  	for(ll i=0;i<n;i++){
  		for(ll j=0;j<n;j++){
  			if(i==0) ans[i][j]=1;
  		}
  	}
  	printGrid(ans);
  	return;
  }
  if(k%4!=0){
  	cout<<"No\n";
  	return;
  }
  cout<<"Yes\n";
  ll ind=0;
  while(k){
  	for(ll i=0;i<n && k;i++){
 
  		ans[i][ind]=ans[i][ind+1]=1;
  		k-=2;
  	}
  	ind+=2;
  }
  printGrid(ans);
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
