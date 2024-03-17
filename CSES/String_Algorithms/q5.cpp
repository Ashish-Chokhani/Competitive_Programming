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
	ll n=s.length();
	s+=s;
	ll hash[2*n+1];
	ll prime=131,x=1;
	hash[0]=s[0]-'a';
	for(ll i=1;i<2*n;i++){
		x*=prime;
		x%=mod;
		hash[i]=((s[i]-'a')*x)%mod+hash[i-1];
		hash[i]%=mod;
	}
	ll modularInverse[2*n+1];
	for(ll i=1;i<=2*n;i++){
		modularInverse[i]=modInv(binexp(prime,i));
	}
	
	auto getHash=[&](ll l,ll r)->ll{
		ll val=hash[r];
		if(l>=1){
			val=((val-hash[l-1])%mod+mod)%mod;
			val*=modularInverse[l];
			val%=mod;
		}
		return val;
	};
	
	
	auto isSamePrefix=[&](ll l,ll cur_ind,ll len)->bool{
		return getHash(cur_ind,cur_ind+len-1)==getHash(l,l+len-1);
	};
	
	ll cur_ind=0;
	for(ll i=1;i<n;i++){
		ll l=0,r=n,longest_length=0;
		while(l<r){
			ll mid=(l+r)>>1;
			if(isSamePrefix(i,cur_ind,mid)){
				l=mid+1;
				longest_length=mid;
			}
			else{
				r=mid;
			}
		}
		if(s[cur_ind+longest_length]>s[i+longest_length]) cur_ind=i;
	}
	cout<<s.substr(cur_ind,n)<<endl;
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