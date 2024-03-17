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
 
bool isPossible(ll val,vector<ll>&arr){
	ll n=(ll)arr.size();
	set<pair<ll,ll>>st;
	for(ll i=0;i<n;i++){
		st.insert({arr[i],i});
	}
	auto it=st.end();
	--it;
	ll power=(*it).first;
	ll ind=(*it).second;
	st.erase(it);
	if(power>val) return false;
	ll removed_l=ind,removed_r=ind;
	val--;
	while(!st.empty()){
		ll maxi_ind,prev_l=-1,next_r=n;
		if(removed_l>=1) prev_l=removed_l-1;
		if(removed_r<n-1) next_r=removed_r+1;
		if(prev_l!=-1){
			if(next_r==n) maxi_ind=prev_l;
			else{
				if(arr[prev_l]<arr[next_r]) maxi_ind=prev_l;
				else maxi_ind=next_r;
			}
		}
		else{
			maxi_ind=next_r;
		}
		if(arr[maxi_ind]>val) return false;
		val--;
		st.erase(st.find({arr[maxi_ind],maxi_ind}));
		if(maxi_ind==prev_l) removed_l--;
		else removed_r++;
	}
	return true;
}
 
void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  ll l=0,r=1e15,ans=1e15;
  while(l<=r){
  	ll mid=(l+r)>>1;
  	if(isPossible(mid,arr)){
  		ans=mid;
  		r=mid-1;
  	}
  	else{
  		l=mid+1;
  	}
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