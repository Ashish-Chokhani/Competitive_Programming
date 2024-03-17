#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=998244353;

ll fun(ll i,ll cntOpen,ll n,string &s,vector<vector<ll>>&dp){
    if(i==n) return cntOpen==0;
    if(cntOpen<0) return 0;

    if(dp[i][cntOpen]!=-1)
    return dp[i][cntOpen];

    if(s[i]=='(') return fun(i+1,cntOpen+1,n,s,dp)%mod;
    if(s[i]==')') return fun(i+1,cntOpen-1,n,s,dp)%mod;

    ll open=fun(i+1,cntOpen+1,n,s,dp)%mod;
    ll close=fun(i+1,cntOpen-1,n,s,dp)%mod;

    return dp[i][cntOpen]=(open%mod+close%mod)%mod;
}

void solve()
{
    string s;
    cin>>s;
    vector<vector<ll>>dp(3002,vector<ll>(3002,-1));
    cout<<fun(0,0,s.length(),s,dp)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}