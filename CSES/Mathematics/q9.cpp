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

bool isPrime(ll n){
	return n==2 || n==3 || n==5 || n==7 || n==11 || n==13 || n==17 || n==19 || n==23 || n==29;
}

void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  map<ll,ll>mapOfNumbers;
  ll id=0;
  vector<ll>primes;
  for(ll i=2;i<30;i++){
  	if(isPrime(i)){
  		mapOfNumbers[i]=id++;
  		primes.push_back(i);
  	}
  }
  ll sz=(ll)primes.size();
  map<ll,ll>freq,whatMask;
  for(ll i=0;i<n;i++){
  	ll mask=0;
  	for(ll &num:primes){
  		if(arr[i]%num==0){
  			mask |= (1LL<<mapOfNumbers[num]);
  		}
  	}
  	whatMask[arr[i]]=mask;
  	freq[mask]++;
  }
  ll ans=0;
  for(ll &num:arr){
  	ll cur_mask=whatMask[num];
  	freq[cur_mask]--;
  	for(ll mask=0;mask<(1LL<<sz);mask++){
  		if((mask & cur_mask)==0) ans+=freq[mask];
  	}
  freq[cur_mask]++;
  }
  cout<<ans/2<<endl;
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