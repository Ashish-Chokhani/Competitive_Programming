#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll H,W,N;
    cin>>H>>W>>N;
    vector<vector<ll>>arr(H+1,vector<ll>(W+1,0));
    while(N--){
        ll a,b;
        cin>>a>>b;
        arr[a][b]=1;
    }
    vector<vector<ll>>dp(H+1,vector<ll>(W+1,0));
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            if(arr[i][j]) continue;
            dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }
    ll ans=0;
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            ans+=dp[i][j];
        }
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