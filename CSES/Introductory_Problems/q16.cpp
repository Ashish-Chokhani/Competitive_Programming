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

ll miniDiff(ll i,ll cur_sum,ll s,vector<ll>&arr){
	if(i<0){
		ll val1=cur_sum;
		ll val2=s-cur_sum;
		return abs(val1-val2);
	}
	ll v1=miniDiff(i-1,cur_sum+arr[i],s,arr);
	ll v2=miniDiff(i-1,cur_sum,s,arr);
	return min(v1,v2);
}

void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  ll s=0;
  for(auto &x:arr){
    cin>>x;
    s+=x;
  }
  cout<<miniDiff(n-1,0,s,arr)<<"\n";
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