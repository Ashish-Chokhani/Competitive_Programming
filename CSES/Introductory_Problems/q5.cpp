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
  if(n==1){
  	cout<<"1\n";
  	return;
  }
  if(n<=3){
  	cout<<"NO SOLUTION\n";
  	return;
  }
  vector<ll>ans;
  ll i=1,j=n;
  while(i<(n+1)/2){
  	ans.push_back(i);
  	ans.push_back(j);
  	i++;
  	j--;
  }
  if(n&1){
  	ans.insert(ans.begin(),i);
  }
  else{
  	ans.insert(ans.begin(),j);
  	ans.push_back(i);
  }
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