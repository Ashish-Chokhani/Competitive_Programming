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
  ll n,m,k;
  cin>>n>>m>>k;
  vector<vector<ll>>mat(n,vector<ll>(n,0));
  for(ll i=0;i<m;i++){
    ll u,v;
    cin>>u>>v;
    --u;--v;
    mat[u][v]++;
  }
  auto multiply_matrix=[&](vector<vector<ll>>mat1,vector<vector<ll>>mat2){
  	ll n1=mat1.size();
  	ll n2=mat2[0].size();
  	vector<vector<ll>>res(n1,vector<ll>(n2,0));
  	for(ll i=0;i<n1;i++){
  		for(ll j=0;j<n2;j++){
  			for(ll k=0;k<(ll)mat2.size();k++){
  				res[i][j]+=mat1[i][k]*mat2[k][j];
  				res[i][j]%=mod;
  			}
  		}
  	}
  	return res;
  };
  
  auto binExp=[&](vector<vector<ll>>mat,ll n){
    ll sz=mat.size();
  	vector<vector<ll>>res(sz,vector<ll>(sz,0));
    for(ll i=0;i<sz;i++){
      res[i][i]=1;
    }
  	while(n){
  		if(n&1) res=multiply_matrix(res,mat);
  		mat=multiply_matrix(mat,mat);
  		n>>=1;
  	}
  	return res;
  };
  vector<vector<ll>>res=binExp(mat,k);
  cout<<res[0][n-1]<<endl;
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