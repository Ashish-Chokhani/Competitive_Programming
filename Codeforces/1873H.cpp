#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> Djkistra(ll src,vector<ll>*adj,ll n)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(n + 1, 1e12);
    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        ll node = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            ll cur_dis = dist[it];
            if (dis + 1 < cur_dis)
            {
                dist[it] = dis + 1;
                pq.push(make_pair(dis + 1, it));
            }
        }
    }
    return dist;
}

void DFS(ll cur,ll par,vector<ll>*adj,vector<ll>&vis,vector<ll>&parent,vector<ll>&cycle,ll &flag){
    vis[cur]=1;
    parent[cur]=par;
    for(auto it:adj[cur]){
        if(!vis[it]){
            DFS(it,cur,adj,vis,parent,cycle,flag);
        }
        else if(vis[it] && it!=par){
            ll now=cur;
            ll cnt=0;
            while(now!=it && cnt<5 && flag){
                cycle.push_back(now);
                now=parent[now];
            }
            if(flag)
            cycle.push_back(it);
            flag=0;
        }
    }
}

void solve()
{
    ll n,a,b;
    cin>>n>>a>>b;
    --a;
    --b;
    vector<ll>adj[n+1];
    for(ll i=1;i<=n;i++){
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll>cycle;
    vector<ll>vis(n+1,0),parent(n+1,-1);
    ll flag=1;
    DFS(0,-1,adj,vis,parent,cycle,flag);
    vector<ll>dj=Djkistra(b,adj,n);
    vector<ll>dj2=Djkistra(a,adj,n);
    ll node=-1,min_dist=1e12;
    for(auto it:cycle){
        if(dj[it]<dj2[it]){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    ll cnt=0;
    while (t--)
    {
        solve();
    }
    return 0;
}