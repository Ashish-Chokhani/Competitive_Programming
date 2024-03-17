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

void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  map<ll,vector<ll>>where;
  ll ind=0;
  for(auto &x:arr){
    cin>>x;
    where[x].push_back(ind++);
  }
  ll pre[n];
  pre[0]=arr[0];
  for(ll i=1;i<n;i++) pre[i]=arr[i]+pre[i-1];
  auto containsSameElement=[&](ll l,ll r)->bool{
  	ll val=arr[r];
  	if(val!=arr[l]) return false;
  	ll ind1=lower_bound(where[val].begin(),where[val].end(),l)-where[val].begin();
  	ll ind2=lower_bound(where[val].begin(),where[val].end(),r)-where[val].begin();
  	return ind2-ind1==r-l;
  };
  auto findRangeSum=[&](ll l,ll r)->ll{
  	if(l>r || l<0 || r==n) return 0;
  	if(containsSameElement(l,r)) return arr[l];
  	if(l==0) return pre[r];
  	return pre[r]-pre[l-1];
  };
  auto searchLeft=[&](ll i){
  	ll l=0,r=i-1;
  	if(findRangeSum(l,r)<arr[i]) return -1;
  	int ans=-1;
  	while(l<=r){
  		int mid=(l+r)>>1;
  		if(findRangeSum(mid,i-1)>arr[i]){
  			ans=max(ans,mid);
  			l=mid+1;
  		}
  		else r=mid-1;
  	}
  	return ans;
  };
  // TO DO: check whether segment l,r contains same elements
  auto searchRight=[&](ll i)->ll{
  	ll l=i+1,r=n-1;
  	ll ans=n;
  	while(l<=r){
  		ll mid=(l+r+1)>>1;
  		if(findRangeSum(i+1,mid)>arr[i]){
  			ans=min(ans,mid);
  			r=mid-1;
  		}
  		else l=mid+1;
  	}
  	return ans;
  };
  auto findTime=[&](ll i,ll j)->ll{
  	if(i==-1 || j==-1 || i==n || j==n) return -1;
  	return abs(i-j);
  };
  for(ll i=0;i<n;i++){
  	ll l=searchLeft(i);
  	ll r=searchRight(i);
  	if(l==-1) cout<<findTime(i,r)<<" \n"[i==n-1];
  	else if(r==n) cout<<findTime(i,l)<<" \n"[i==n-1];
  	else cout<<min(findTime(i,r),findTime(i,l))<<" \n"[i==n-1];
  }
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}