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

void solve(){
  ll n;
  cin>>n;
  vector<pair<ll,pair<ll,ll>>>arr(n);
  vector<pair<ll,char>>data;
  int ind=0;
  for(pair<ll,pair<ll,ll>> &x:arr){
    cin>>x.first>>x.second.first;
    x.second.second=ind++;
    data.push_back({x.first,'x'});
    data.push_back({x.second.first,'y'});
  }
  sort(arr.begin(),arr.end(),[](pair<ll,pair<ll,ll>>&i1,pair<ll,pair<ll,ll>>&i2){
  	return i1.second.first<i2.second.first || (i1.second.first==i2.second.first && i1.first<=i2.first);
  });
  // sort(data.begin(),data.end(),[](pair<ll,pair<ll,ll>>&i1,pair<ll,pair<ll,ll>>&i2){
  // 	return i1.second.first<i2.second.first || (i1.second.first==i2.second.first && i1.first<=i2.first);
  // });
  int room=0,prev_r,i=0;
  vector<ll>inter;
  vector<int>ans(n,0);
  while(i<n){
  	ll cur_l=arr[i].first;
  	ll cur_r=arr[i].second.first;
  	ll ind=arr[i].second.second;
  	// Count number of r>=cur_l Then Assign val+1
  	int index=lower_bound(inter.begin(),inter.end(),cur_l)-inter.begin();
  	cout<<i<<" "<<index<<" "<<inter.size()<<" "<<ind<<"\n";
  	index=inter.size()-index;
  	ans[ind]=index+1;
  	inter.push_back(cur_r);
  	i++;
  }
  set<ll>st;
  for(auto &num:ans){
  	st.insert(num);
  }
  cout<<st.size()<<"\n";
  for(auto &num:ans){
  	cout<<num<<" ";
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