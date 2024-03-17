#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(ll cur,ll par,vector<pair<ll,pair<ll,ll>>>*adj,vector<ll>&dp,multiset<pair<ll,pair<ll,ll>>,greater<pair<ll,pair<ll,ll>>>>*st,ll &sum){
    ll nchild=0;
    for(auto it:adj[cur]){
        if(it.first!=par){
            nchild++;
            DFS(it.first,cur,adj,dp,st,sum);
            dp[cur]+=dp[it.first];
            sum+=it.second.first*dp[it.first];
            st[it.second.second%2].insert({(it.second.first-it.second.first/2)*dp[it.first],{it.second.first/2,dp[it.first]}});
        }
    }
    if(nchild==0)
    dp[cur]=1;
}

void insertInto(multiset<pair<ll,pair<ll,ll>>,greater<pair<ll,pair<ll,ll>>>>*st,vector<ll>&arr,ll ind,ll sum,ll S){
    while(!st[ind].empty() && sum>S){
        auto it=st[ind].begin();
        pair<ll,pair<ll,ll>>val=*it;
        st[ind].erase(it);
        sum-=val.first;
        arr.push_back(val.first);
        if((val.second.first-val.second.first/2)*val.second.second>0)
        st[ind].insert({(val.second.first-val.second.first/2)*val.second.second,{val.second.first/2,val.second.second}});
    }
}

void solve()
{
    ll n,S;
    cin>>n>>S;
    vector<pair<ll,pair<ll,ll>>>adj[n+1];
    for(ll i=0;i<n-1;i++){
        ll u,v,wt,c;
        cin>>u>>v>>wt>>c;
        --u;
        --v;
        adj[u].push_back({v,{wt,c}});
        adj[v].push_back({u,{wt,c}});
    }
    multiset<pair<ll,pair<ll,ll>>,greater<pair<ll,pair<ll,ll>>>>st[2];
    vector<ll>dp(n+1);
    ll sum=0;
    DFS(0,-1,adj,dp,st,sum);
    if(sum<=S){
        cout<<"0\n";
        return;
    }
    ll ans=1e9;
    vector<ll>x,y;
    insertInto(st,x,0,sum,S);
    insertInto(st,y,1,sum,S);
    ll l=0,req=sum-S,r=0;
    ll x_sz=x.size(),y_sz=y.size();
    for(ll i=1;i<x_sz;i++){
        x[i]+=x[i-1];
    }
    for(ll i=1;i<y_sz;i++){
        y[i]+=y[i-1];
    }
    while(l<x_sz){
        ll ind=lower_bound(y.begin(),y.end(),req-x[l])-y.begin();
        if(ind!=y_sz)
        ans=min(ans,2*(l+1)+(ind+1));
        if(req-x[l]<=0)
        ans=min(ans,2*(l+1));
        l++;
    }
    req=sum-S;
     while(r<y_sz){
        ll ind=lower_bound(x.begin(),x.end(),req-y[r])-x.begin();
        if(ind!=x_sz)
        ans=min(ans,2*(ind+1)+(r+1));
        if(req-y[r]<=0)
        ans=min(ans,(r+1));
        r++;
    }
    cout<<ans<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    ll cnt=0;
    while(t--){
        solve();
    }
    return 0;
}