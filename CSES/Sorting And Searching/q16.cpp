#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
template using ordered_set = tree<T, null_type, less, rb_tree_tag, tree_order_statistics_node_update>;


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

void solve(){
  ll n;
  cin>>n;
  vector<pair<ll,pair<ll,ll>>>intervals(n);
  for(ll i=0;i<n;i++){
  	cin>>intervals[i].first>>intervals[i].second.first;
  	intervals[i].second.second=i;
  }
  sort(intervals.begin(),intervals.end(),[](pair<ll,pair<ll,ll>>&i1,pair<ll,pair<ll,ll>>&i2){
  	return (i1.first<i2.first || (i1.first==i2.first && i1.second.first>=i2.second.first));
  });
  vector<int>ans(n,0);
  ll min_val=intervals[n-1].second.first;
  unordered_set<ll>st;
  for(ll i=n-2;i>=0;i--){
  	ll r=intervals[i+1].second.first;
  	ll cur_r=intervals[i].second.first;
  	ll ind=intervals[i].second.second;
  	min_val=min(min_val,r);
  	st.insert(r);
  	if(min_val<=cur_r) {
  		//ans[ind]=1;
  		//int index=distance(st.begin(),st.lower_bound(cur_r+1));	
  		int index=st.order_of_key(cur_r+1);
  		ans[ind]=index;
  	}
  }
  for(auto &x:ans){
  	cout<<x<<" ";
  }
  cout<<"\n";
  fill(ans.begin(),ans.end(),0LL);
  st.clear();
  ll max_r=intervals[0].second.first;
  st.insert(max_r);
  for(ll i=1;i<n;i++){
  	ll r=intervals[i].second.first;
  	ll ind=intervals[i].second.second;
  	if(r<=max_r){
  		int index=distance(st.begin(),st.lower_bound(r));	
  		index=st.size()-index;
  		ans[ind]=index;
  	}
  	st.insert(r);
  	max_r=max(max_r,r);
  }
  for(auto &x:ans){
  	cout<<x<<" ";
  }
  cout<<"\n";
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