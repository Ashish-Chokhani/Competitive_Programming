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

ll placeDisks(ll i,ll maxB,ll maxC,ll n,vector<pair<ll,ll>>&ans){
	if(i==n+1){
		return 0;
	}
	int move1=0,move2=0;
	if(i<=maxB){
		maxB=i
	}
}

void solve(){
  ll n;
  cin>>n;
  
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
    // cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}