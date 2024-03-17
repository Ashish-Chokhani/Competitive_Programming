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

void solve(){
  ll n;
  cin>>n;
  ll dp[n+1];
  memset(dp,0LL,sizeof(dp));
  dp[0]=1;
  for(ll i=1;i<=n;i++){
  	for(ll j=1;j<=6;j++){
  		if(i-j<0) continue;
  		dp[i]+=dp[i-j]%mod;
  		dp[i]%=mod;
  	}
  }
  cout<<dp[n]<<endl;
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