#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>cost(n);
    for(ll i=0;i<n;i++)
    {
        cin>>cost[i];
    }
    vector<ll>adj[n];
    for(ll i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll>vis(n+1,0);
    ll sz=0;
    queue<pair<ll,ll>> pq;
    set<pair <ll,ll> >st;
    for(ll i=0;i<n;i++)
    {
        if(cost[i]==0)
        {
        pq.push({0,i});
        vis[i]=1;
        sz++;
        break;
        }
    }
    while(!pq.empty())
    {
        ll node=pq.front().second;
        pq.pop();
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(cost[it]<=sz)
                {
                vis[it]=1;
                pq.push({cost[it],it});
                sz++;
                }
                else
                {
                    st.insert({cost[it],it});
                }
            }
        }
        for(auto it=st.begin(),it!)
        {
            if(it.first>sz)
            break;
            pair<ll,ll> val={it.first,it.second};
            st.erase(it);
            // pq.push(val);
            // sz++;
            // vis[val.second]=1;
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])
        {
            cout<<"NO\n";
            return;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
