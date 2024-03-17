#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fact[11];

void calcFact(){
    fact[0]=1;
    for(ll i=1;i<=10;i++) fact[i]=i*fact[i-1];
}

bool isValidMask(ll cur_mask,ll original_mask,vector<pair<ll,ll>>&mp){
    ll isTaken = cur_mask ^ original_mask;

    if(isTaken==0) return false;

    ll bit=0;
    map<ll,ll>newTeam;
    while(isTaken>0){
        if(isTaken & 1) newTeam[bit]=1;
        bit++;
        isTaken>>=1;
    }
    for(auto  it:mp){
        if(newTeam[it.first] && newTeam[it.second]) return false;
    }
    return true;
}

void allPossibleMasks(ll i,ll n,ll cur_mask,ll mask,vector<pair<ll,ll>>&mp,vector<ll>&Masks){
    //Ensure at least 1 memeber in each team
    if(i==n){
        if(isValidMask(cur_mask,mask,mp)) Masks.push_back(cur_mask);
        return;
    }
    allPossibleMasks(i+1,n,cur_mask,mask,mp,Masks);
    if((cur_mask>>i) & 1) allPossibleMasks(i+1,n,cur_mask & ~(1<<i),mask,mp,Masks);
}

ll fun(ll t,ll mask,ll n,vector<pair<ll,ll>>&mp,vector<vector<ll>>&dp){
    if(t==0) return mask==0;

    if(mask==0) return t==0;

    if(dp[t][mask]!=-1) return dp[t][mask];

    vector<ll> Masks;
    allPossibleMasks(0,n,mask,mask,mp,Masks);
    ll ans=0;
    for(auto it:Masks){
        ans+=fun(t-1,it,n,mp,dp);
    }
    return dp[t][mask]=ans;
}



void solve()
{
    ll n,t,m;
    cin>>n>>t>>m;
    calcFact();
    vector<vector<ll>>dp(t+1,vector<ll>(1<<n,-1));
    vector<pair<ll,ll>>mp(m);
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        mp[i].first=u;
        mp[i].second=v;
    }
    ll val=fun(t,(1<<n)-1,n,mp,dp);
    cout<<val/fact[t]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}