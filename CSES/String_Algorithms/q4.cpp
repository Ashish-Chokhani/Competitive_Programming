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
 
ll binexp(ll a,ll n){
	ll res=1;
	while(n){
		if(n&1) res*=a;
		res%=mod;
		n>>=1;
		a*=a;
		a%=mod;
	}
	return res;
}
 
ll modInv(ll x){
	return binexp(x,mod-2);
}
 
void solve(){
	string s;
	cin>>s;
	ll n=(ll)s.length();
	ll hash[n+1];
	memset(hash,0,sizeof(hash));
	ll prime=131;
	hash[0]=s[0]-'a';
	for(ll i=1;i<n;i++){
		hash[i]=(s[i]-'a')*binexp(prime,i)+hash[i-1];
		hash[i]%=mod;
	}
	ll modularInverse[n+1];
	for(ll i=1;i<=n;i++){
		modularInverse[i]=modInv(binexp(prime,i));
	}
	
	auto getHash=[&](ll l,ll r)->ll{
		ll val=hash[r];
		if(l>=1){
			val=(val-hash[l-1]%mod)+mod;
			val%=mod;
			// val*=modInv(binexp(prime,l));
			val*=modularInverse[l];
			val%=mod;			
		}
		return val;
	};
	for(ll i=0;i<n;i++){
		ll len=i+1;
		ll cur_hash=hash[i];
		bool ok=true;
		for(ll j=0;j<n;j+=len){
			if(j+len-1>=n){
				ll new_len=n-j;
				ll new_hash=getHash(0,new_len-1);
				if(getHash(j,n-1)!=new_hash) ok=false;
			}
			else{
				if(getHash(j,j+len-1)!=cur_hash){
					ok=false;
					break;
				}
			}
		}
		if(ok) cout<<len<<" ";
	}
	cout<<endl;
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