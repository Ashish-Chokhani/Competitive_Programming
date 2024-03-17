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
  ll n,k;
  cin>>n>>k;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  ll i=0,j=0,ans=0,cntDistinct=0;
  map<ll,ll>mp;
  while(j<n){
  	while(j<n && cntDistinct<=k){
  		mp[arr[j]]++;
	  	if(mp[arr[j]]==1) cntDistinct++;
	  	j++;
	  }
	while(i<n && cntDistinct>k){
  		mp[arr[j]]++;
	  	if(mp[arr[j]]==1) cntDistinct++;
	  	j++;
	  }
	mp[arr[i]]--;
	if(mp[arr[i]]==0) cntDistinct--;
	i++;
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