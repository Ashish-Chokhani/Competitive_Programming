#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur,ll par,vector<pair<ll,ll>>*adj,vector<ll>&dp,multiset<pair<ll,pair<ll,ll>>,greater<pair<ll,pair<ll,ll>>>>&st,ll &sum){
    ll nchild=0;
    for(auto it:adj[cur]){
        if(it.first!=par){
            nchild++;
            DFS(it.first,cur,adj,dp,st,sum);
            dp[cur]+=dp[it.first];
            sum+=it.second*dp[it.first];
            st.insert({(it.second-it.second/2)*dp[it.first],{it.second/2,dp[it.first]}});
        }
    }
    if(nchild==0)
    dp[cur]=1;
}

void solve()
{
    ll n,S;
    cin>>n>>S;
    vector<pair<ll,ll>>adj[n+1];
    for(ll i=0;i<n-1;i++){
        ll u,v,wt;
        cin>>u>>v>>wt;
        --u;
        --v;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    multiset<pair<ll,pair<ll,ll>>,greater<pair<ll,pair<ll,ll>>>>st;
    vector<ll>dp(n+1);
    ll sum=0;
    DFS(0,-1,adj,dp,st,sum);
    ll ans=0;
    while(sum>S){
        auto it=st.begin();
        pair<ll,pair<ll,ll>>val=*it;
        st.erase(it);
        sum-=val.first;
        st.insert({(val.second.first-val.second.first/2)*val.second.second,{val.second.first/2,val.second.second}});
        ans++;
    }
    cout<<ans<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    ll cnt=0;
    while(t--){
        cnt++;
        if(cnt==34){
            ll n,S;
            cin>>n>>S;
            cout<<n<<"."<<S<<".";
            vector<pair<ll,ll>>adj[n+1];
            for(ll i=0;i<n-1;i++){
            ll u,v,wt;
            cin>>u>>v>>wt;
            cout<<u<<"."<<v<<"."<<wt<<".";
            --u;
            --v;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            }          
        }
        else
        solve();
    }
    return 0;
}