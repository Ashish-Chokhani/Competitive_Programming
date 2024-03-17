#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

void calculateHash(ll cur,ll par,vector<ll>&Hash,ll hashvalue,vector<ll>*adj){
    Hash[cur]=1;
    for(auto it:adj[cur]){
        if(it==par) continue;
        calculateHash(it,cur,Hash,hashvalue,adj);
        Hash[cur]*=(((Hash[it]+(adj[it].size()-1))%MOD)*hashvalue)%MOD;
        Hash[cur]%=MOD;
    }
}

bool isSymmetrical(ll cur,ll par,vector<ll>*adj,vector<ll>&Hash){
    set<ll>st;
    for(auto it:adj[cur]){
        if(it==par) continue;
        if(st.find(Hash[it])==st.end()) st.insert(Hash[it]);
        else st.erase(st.find(Hash[it]));
    }
    ll sz=st.size();
    if(sz==0) return true;
    if(sz>1) return false;

    ll child;
    for(auto it:adj[cur]){
        if(it==par) continue;
        if(st.find(Hash[it])!=st.end()){
            child=it;
            break;
        }
    }
    return isSymmetrical(child,cur,adj,Hash);
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>adj[n];
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    vector<ll>Hash(n+1,0);
    calculateHash(0,-1,Hash,104729,adj);
    cout<<((isSymmetrical(0,-1,adj,Hash))?"YES\n":"No\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    ll cnt=0;
    while(t--){
        solve();
    }
}