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

ll block_size;

struct Query
{
	ll l,r,idx;
	bool operator<(Query other) const
	{
		return make_pair(l/block_size,r)<make_pair(other.l/block_size,other.r);
	}
};

void solve(){
  ll n,Q;
  cin>>n>>Q;
  block_size=sqrt(n)+1;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  auto compresseElements=[&](vector<ll>arr){
  	vector<ll>compressed(n);
  	vector<ll>temp=arr;
  	sort(temp.begin(),temp.end());
  	map<ll,ll>where;
  	ll id=1;
  	for(ll i=0;i<n;i++){
  		if(where[temp[i]]!=0) continue;
  		where[temp[i]]=id++;
  	}
  	for(ll i=0;i<n;i++){
  		compressed[i]=where[arr[i]];
  	}
  	return compressed;
  };
  vector<ll>compressed=compresseElements(arr);  
  vector<ll>mp(n+1,0);
  vector<Query>queries(Q);
  for(ll i=0;i<Q;i++){
  	cin>>queries[i].l>>queries[i].r;
  	--queries[i].l;--queries[i].r;
  	queries[i].idx=i;
  }
  sort(queries.begin(),queries.end());
  vector<ll>ans(Q);
  ll cur_l=0,cur_r=-1,cntDisticts=0;
  for(Query q:queries){
  	ll idx=q.idx;
  	ll l=q.l;
  	ll r=q.r;
  	while(cur_l>l){
  		cur_l--;
  		mp[compressed[cur_l]]++;
  		if(mp[compressed[cur_l]]==1) cntDisticts++;
  	}
  	while(cur_r<r){
  		cur_r++;
  		mp[compressed[cur_r]]++;
  		if(mp[compressed[cur_r]]==1) cntDisticts++;
  	}
  	while(cur_l<l){
  		mp[compressed[cur_l]]--;
  		if(mp[compressed[cur_l]]==0) cntDisticts--;
  		cur_l++;
  	}
  	while(cur_r>r){
  		mp[compressed[cur_r]]--;
  		if(mp[compressed[cur_r]]==0) cntDisticts--;
  		cur_r--;
  	}
  	ans[idx]=cntDisticts;
  }
  for(ll &x:ans) cout<<x<<endl;
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