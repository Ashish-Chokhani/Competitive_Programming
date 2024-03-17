#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

//Check for 1 length 
 
void detectCycle(ll cur,ll par,vector<ll>*adj,vector<ll>&vis,vector<ll>&parent,vector<ll>&cycles,ll &c){
    vis[cur]=1;
    parent[cur]=par;
    for(auto it:adj[cur]){
        if(!vis[it]){
            detectCycle(it,cur,adj,vis,parent,cycles,c);
        }
        else if(vis[it]==1){
            c=1;
            cycles.push_back(it);
            ll temp=cur;
            while(temp!=it){
                cycles.push_back(temp);
                temp=parent[temp];
            }
        }
    }
    vis[cur]=2;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll flag=1;
    vector<ll>adj[n+1];
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        --x;
        if(k==1) flag=flag & (i==x);
        adj[i].push_back(x);
    }
    if(k==1){
        cout<<((flag==1) ? "YES\n": "NO\n");
        return;
    } 
    vector<ll>vis(n+1,0),parent(n+1),ok(n,0);
    for(ll i=0;i<n;i++){
        ll c=-1;
        if(!vis[i]){
            vector<ll>cycles;
            detectCycle(i,-1,adj,vis,parent,cycles,c);
            ll sz=cycles.size();
            if(sz!=k && c!=-1){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}