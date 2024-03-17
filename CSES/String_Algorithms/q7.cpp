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

void solve(){
  ll n,m,z;
  cin>>n>>m>>z;
  vector<vector<ll>>grid(n,vector<ll>(m,0));
  for(ll i=0;i<n;i++){
  	for(ll j=0;j<m;j++){
  		char ch;
  		cin>>ch;
  		grid[i][j]=ch=='#';
  	}
  }
  if(n>m){
  	vector<vector<ll>>temp(m,vector<ll>(n));
  	for(ll i=0;i<m;i++){
  		for(ll j=0;j<n;j++){
  			temp[i][j]=grid[j][i];
  		}
  	}
  	grid=temp;
  	swap(n,m);
  }
  vector<vector<ll>>pre(n,vector<ll>(m,0));
  for(ll i=0;i<n;i++){
  	for(ll j=0;j<m;j++){
  		pre[i][j]=grid[i][j]+(j?pre[i][j-1]:0);
  	}
  }
  
  auto findRangeSum=[&](ll l,ll r,vector<ll>&pre)->ll{
  	l=max(0LL,l);
  	r=min(m-1,r);
  	ll val=pre[r];
  	if(l>=1) val-=pre[l-1];
  	return val;
  };
  
  ll ans=0,atSum=0;
  for(ll i=0;i<n;i++){
  	for(ll j=0;j<m;j++){
  		atSum=0;
  		for(ll k=i,use=0;k>=0 && i-k<=z;k--,use++){
  			ll l=j,r=j+z-use;
  			atSum+=findRangeSum(l,r,pre[k]);
  		}
  		ans=max(ans,atSum);
  		atSum=0;
  		for(ll k=i,use=0;k<n && k-i<=z;k++,use++){
  			ll l=j,r=j+z-use;
  			atSum+=findRangeSum(l,r,pre[k]);
  		}
  		ans=max(ans,atSum);
  		atSum=0;
  		for(ll k=i,use=0;k>=0 && i-k<=z;k--,use++){
  			ll l=j-z+use,r=j;
  			atSum+=findRangeSum(l,r,pre[k]);
  		}
  		ans=max(ans,atSum);
  		atSum=0;
  		for(ll k=i,use=0;k<n && k-i<=z;k++,use++){
  			ll l=j-z+use,r=j;
  			atSum+=findRangeSum(l,r,pre[k]);
  		}
  		ans=max(ans,atSum);
  	}
  }
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