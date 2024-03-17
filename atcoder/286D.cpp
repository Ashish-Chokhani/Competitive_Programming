#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{ 
    ll n,s;
    cin>>n>>s;
    vector<ll>A(n),B(n);
    for(ll i=0;i<n;i++){
        cin>>A[i]>>B[i];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(s+1,0));
    dp[0][0]=1;
    for(ll i=1;i<=n;i++){
        for(ll k=0;k<=s;k++){
            for(ll j=0;j<=B[i-1];j++){
                if(k>=j*A[i-1])
                dp[i][k] = dp[i][k] | dp[i-1][k-(j*A[i-1])];
            }
        }
    }
    if(dp[n][s]) cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}