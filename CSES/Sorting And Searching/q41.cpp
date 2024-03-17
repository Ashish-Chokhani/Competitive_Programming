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
// for erase use: st.erase(st.find_by_order(val);

bool isValid(ll num,ll m){
	return num>=1 && num<=m;
}

ll findDifference(ll prev_pos_v1,ll prev_pos_v2,ll cur_pos_v1,ll cur_pos_v2,ll v1,ll v2,ll m){
	if(!isValid(v1,m) || !isValid(v2,m)) return 0;
	ll f1=(prev_pos_v1>prev_pos_v2)^(v1>v2);
	ll f2=(cur_pos_v1>cur_pos_v2)^(v1>v2);
	return f2-f1;
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<ll>arr(n);
  map<ll,ll>where;
  ll ind=0;
  for(auto &x:arr){
    cin>>x;
    where[x]=ind++;
  }
  ll ans=1;
  for(ll i=2;i<=n;i++){
  	ans+=where[i-1]>where[i];
  }
  //cout<<ans<<"\n";
  while(m--){
  	ll l,r;
  	cin>>l>>r;
  	--l;
  	--r;
  	ll v1=min(arr[l],arr[r]);
  	ll v2=max(arr[l],arr[r]);
  	ll v3=v1-1;
  	ll v4=v2+1;
  	ll v5=v1+1;
  	ll v6=v2-1;
  	//v3 v1  v1 v5 v6 v2  v2 v4
  	
  	ll prev_pos_v3=where[v3];
  	ll prev_pos_v1=where[v1];
  	ll prev_pos_v2=where[v2];
  	ll prev_pos_v4=where[v4];
  	ll prev_pos_v5=where[v5];
  	ll prev_pos_v6=where[v6];
  	
  	where[arr[l]]=r;
  	where[arr[r]]=l;
  	
  	ll cur_pos_v3=where[v3];
  	ll cur_pos_v1=where[v1];
  	ll cur_pos_v2=where[v2];
  	ll cur_pos_v4=where[v4];
  	ll cur_pos_v5=where[v5];
  	ll cur_pos_v6=where[v6];
  	
  	swap(arr[l],arr[r]);
  	
  	ans+=findDifference(prev_pos_v3,prev_pos_v1,cur_pos_v3,cur_pos_v1,v3,v1,n);
  	ans+=findDifference(prev_pos_v1,prev_pos_v5,cur_pos_v1,cur_pos_v5,v1,v5,n);
  	if((v2-v1)!=1)ans+=findDifference(prev_pos_v6,prev_pos_v2,cur_pos_v6,cur_pos_v2,v6,v2,n);
  	ans+=findDifference(prev_pos_v2,prev_pos_v4,cur_pos_v2,cur_pos_v4,v2,v4,n);
  	cout<<ans<<"\n";
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
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}