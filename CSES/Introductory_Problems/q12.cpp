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
  string s;
  cin>>s;
  vector<ll>freq(26,0);
  ll oddFreq=0;
  char oddChar='#';
  for(char &ch:s){
  	freq[ch-'A']++;
  }
  for(int i=0;i<26;i++){
  	ll num=freq[i];
  	if(num&1){
  		oddFreq++;
  		oddChar=(char)(i+'A');
  	}
  }
  if(oddFreq>1){
  	cout<<"NO SOLUTION\n";
  	return;
  }
  int n=(int)s.length();
  int i=0,j=n-1;
  vector<char>ans(n);
  int ind=0;
  while(i<j){
  	if(freq[ind]>1){
  		ans[i]=(char)(ind+'A');
  		ans[j]=(char)(ind+'A');
  		freq[ind]-=2;
  		i++;
  		j--;
  	}
  	else{
  		ind++;
  	}
  }
  if(oddFreq==1){
  	ans[i]=oddChar;
  }
  for(char &ch:ans){
  	cout<<ch;
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