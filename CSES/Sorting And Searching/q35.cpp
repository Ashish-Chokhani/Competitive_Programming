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

void removeElememts(vector<ll>&arr){
	ll sz=arr.size();
	if(sz==1){
		cout<<arr[0]<<"\n";
		return;
	}
	ll i=0;
	vector<ll>new_arr;
	ll flag=0;
	while(i<sz){
		if(i&1) cout<<arr[i]<<" ";
		else{
			if(i==sz-1) flag=1;
			else new_arr.push_back(arr[i]);
		}
		i++;
	}
	if(flag) new_arr.insert(new_arr.begin(),arr[sz-1]);
	removeElememts(new_arr);
}

void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  iota(arr.begin(),arr.end(),1LL);
  removeElememts(arr);
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