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

void fun(vector<ll>&freq,ll n,string &s,vector<string>&ans){
	if(s.length()==n){
		ans.push_back(s);
		return;
	}
	for(char ch='a';ch<='z';ch++){
		string temp=s;
		if(freq[ch-'a']){
			temp+=ch;
			freq[ch-'a']--;
			fun(freq,n,temp,ans);
			freq[ch-'a']++;
		}
	}
}

void solve(){
	string s;
	cin>>s;
	vector<ll>freq(26,0);
	for(char &ch:s){
		freq[ch-'a']++;
	}
	vector<string>ans;
	string temp="";
	fun(freq,(ll)s.length(),temp,ans);
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(auto &s:ans){
		cout<<s<<"\n";
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