#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void BFS(ll u,ll v,vector<ll>*adj,pair<ll,ll>*ans,vector<ll>&A,vector<ll>&vis){
    queue<pair<ll,pair<ll,ll>>>q;
    q.push({0,{A[u],u}});
    vis[u]=1;
    while(!q.empty()){
        ll cur_dis=q.front().first;
        ll cur_val=q.front().second.first;
        ll node=q.front().second.second;
        q.pop();
        if(cur_dis>ans[v].first) continue;
        for(auto it:adj[node]){
            if(vis[it]) continue;
            vis[it]=1;
            ll totDis=cur_dis+1;
            ll totVal=cur_val+A[it];
            ll prev_dis=ans[it].first;
            if(totDis<=prev_dis){
                ans[it].first=totDis;
                ans[it].second=max(ans[it].second,totVal);
                q.push({totDis,{ans[it].second,it}});
            }
        }
    }
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>adj[n+1];
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        for(ll j=0;j<n;j++){
            if(s[j]=='Y'){
                adj[i].push_back(j);
            }
        }
    }
    ll q;
    cin>>q;
    while(q--){
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        pair<ll,ll>ans[n];
        vector<ll>vis(n+1,0);
        for(ll i=0;i<n;i++){
            ans[i]={1e16,0};
        }
        BFS(u,v,adj,ans,arr,vis);
        if(ans[v].first==1e16) cout<<"Impossible\n";
        else cout<<ans[v].first<<" "<<ans[v].second<<"\n";
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}