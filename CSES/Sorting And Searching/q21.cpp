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
  vector<pair<ll,ll>>arr(n);
  int ind=0;
  for(auto &x:arr){
    cin>>x.first;
    x.second=ind++;
  }
  sort(arr.begin(),arr.end());
  for(ll i=0;i<n;i++){
  	ll req=k-arr[i].first;
  	ll j=0,k=n-1;
  	while(j<k){
  		if(j==i){
  			j++;
  			continue;
  		}
  		if(k==i){
  			k--;
  			continue;
  		}
  		ll s=arr[j].first+arr[k].first;
  		if(s==req){
  			cout<<arr[i].second+1<<" "<<arr[j].second+1<<" "<<arr[k].second+1<<"\n";
  			return;
  		}
  		else if(s<req){
  			j++;
  		}
  		else{
  			k--;
  		}
  	}
  }
  cout<<"IMPOSSIBLE\n";
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