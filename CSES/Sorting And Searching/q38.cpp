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
  ll j=0,cntDistincts=0,ans=0;
  map<ll,ll>freq;
  for(ll i=0;i<n;i++){
  	if(freq[arr[i]]==0) cntDistincts++;
  	freq[arr[i]]++;
  	while(cntDistincts>k){
  		freq[arr[j]]--;
  		if(freq[arr[j]]==0) cntDistincts--;
  		j++;
  	}
  	ans+=i-j+1;
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