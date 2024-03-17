#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll fun(ll i,ll j,ll k,vector<ll>&arr,vector<vector<vector<ll>>>&dp){
    if(i<0){
        return !k;
    }
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    ll pick=0,not_pick=0;
    if(arr[i]<=j) pick=fun(i-1,j-arr[i],k,arr,dp);
    not_pick=fun(i-1,j,k,arr,dp);
    return dp[i][j][k]=pick | not_pick;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.rbegin(),arr.rend());
    vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(k+1,vector<ll>(2,-1)));
    ll val=fun(n-1,k,0,arr,dp);
    if(dp[n-1][k][0]==1) cout<<"First\n";
    else cout<<"Second\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}