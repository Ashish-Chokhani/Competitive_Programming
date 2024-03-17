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


bool isPossibleToMake(ll mid,vector<ll>&arr,ll k){
	ll cnt=0;
	for(auto &x:arr){
		cnt+=mid/x;
		if(cnt>=k) return true;
	}
	return false;
}

void solve(){
  ll n,k;
  cin>>n>>k;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  ll low=1,high=1e18+2,ans=high;
  while(low<=high){
  	ll mid=(low+high)>>1;
  	if(isPossibleToMake(mid,arr,k)){
  		ans=min(ans,mid);
  		high=mid-1;
  	}
  	else{
  		low=mid+1;
  	}
  }
  cout<<ans<<"\n";
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