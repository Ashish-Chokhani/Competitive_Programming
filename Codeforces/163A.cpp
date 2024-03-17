#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;

void solve()
{
    string s;
    cin>>s;
    string t;
    cin>>t;
    ll n=s.length(),m=t.length();
    vector<vector<ll>>dp(5002,vector<ll>(5002,0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(s[i-1]==t[j-1]) dp[i][j]+=(1+dp[i-1][j-1])%mod;
            dp[i][j]%=mod;
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans+=dp[i][m];
        ans%=mod;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}