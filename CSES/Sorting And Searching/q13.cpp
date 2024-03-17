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
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  ll j=0,ans=1,i=1;
  map<ll,ll>lastVisited;
  lastVisited[arr[0]]=1;
  while(i<n){
  	if(!lastVisited[arr[i]] || lastVisited[arr[i]]<j+1){
  		lastVisited[arr[i]]=i+1;
  		i++;
  		continue;
  	}
  	else{
  		ans=max(ans,i-j);
  		j=lastVisited[arr[i]];
  		lastVisited[arr[i]]=i+1;
  		i++;
  	}
  }
  ans=max(ans,i-j);
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