#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(k+1));
    dp[0][0]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=k;j++){
            ll pick=0,not_pick=0;
            if(arr[i-1]<=j) pick=dp[i-1][j-arr[i-1]];
            not_pick=dp[i-1][j];
            dp[i][j]=pick+not_pick;
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<dp[i][k]<<" ";
    }
    cout<<"\n";
    cout<<dp[n][k]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
