#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
bool fun(ll i,ll j,ll m,vector<ll>*adj,vector<ll>&l,vector<ll>&r,vector<vector<ll>>&dp){
    if(j==m)
    return false;
 
    if(dp[i][j]!=-1)
    return dp[i][j];
 
    bool flag=false;
 
    for(ll k=l[j];k<=r[j];k++){
        ll ind=lower_bound(adj[k].begin(),adj[k].end(),i)-adj[k].begin();
        ll sz=adj[k].size();
        if(ind==sz)
        return dp[i][j]=1;
        if(fun(adj[k][ind]+1,j+1,m,adj,l,r,dp))
        return dp[i][j]=1;
    }
    return dp[i][j]=0;
}
 
void solve()
{
    string s;
    cin>>s;
    ll n=s.length();
    vector<ll>adj[10];
    for(ll i=0;i<n;i++){
        adj[s[i]-'0'].push_back(i);
    }
    ll m;
    cin>>m;
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,-1));
    string L,R;
    cin>>L>>R;
    vector<ll>l(m),r(m);
    for(int i=0;i<m;i++){
        l[i]=L[i]-'0';
        r[i]=R[i]-'0';
    }
    if(fun(0,0,m,adj,l,r,dp)) cout<<"YES\n";
    else cout<<"NO\n";
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    solve();
}