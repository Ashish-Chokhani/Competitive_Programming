#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn=252;
vector<vector<vector<ll>>>dp(maxn,vector<vector<ll>>(maxn,vector<ll>(maxn,1e9)));
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n+1),pre(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(ll i=1;i<=n;i++){
        pre[i]=arr[i]+pre[i-1];
    }
    for(ll j=0;j<maxn;j++){
        for(ll k=0;k<maxn;k++){
            dp[0][j][k]=0;
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=m;j++){
            for(ll k=j;k<=m;k++){
                ll extra_ops=abs(pre[i]-k);
                dp[i][j][k]=min(dp[i][j][k],extra_ops+dp[i-1][j][k-j]);
            }
        }
        for(ll j=m-1;j>=0;j--){
            for(ll k=0;k<=m;k++){
                dp[i][j][k]=min(dp[i][j][k],dp[i][j+1][k]);
            }
        }
    }
    cout<<dp[n][0][m]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}