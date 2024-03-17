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
  ll sum=(n*(n+1))/2;
  if(sum&1){
  	cout<<"NO\n";
  	return;
  }
  cout<<"YES\n";
  vector<ll>set1,set2;
  ll i,j;
  if(n&1){
  	set1.push_back(1);
  	set1.push_back(2);
  	set2.push_back(3);
  	i=4;
    j=7;
  }
  else{
  	i=1;
    j=4;
  }
  while(j<=n){
    set1.push_back(i);
    set1.push_back(j);
    set2.push_back(i+1);
    set2.push_back(j-1);
    i=j+1;
    j+=4;
  }
  cout<<set1.size()<<"\n";
  for(auto &num:set1){
  	cout<<num<<" ";
  }
  cout<<"\n";
  cout<<set2.size()<<"\n";
  for(auto &num:set2){
  	cout<<num<<" ";
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