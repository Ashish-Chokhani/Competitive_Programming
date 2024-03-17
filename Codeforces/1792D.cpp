#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>arr(n,vector<ll>(m));
    set<vector<ll>>st;
    for(ll i=0;i<n;i++){
        vector<ll>where(m);
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
            --arr[i][j];
            where[arr[i][j]]=j;
        }
        vector<ll>v(m,-1);
        for(ll j=0;j<m;j++){
            v[where[j]]=j;
            st.insert(v);
        }
    }
    for(ll i=0;i<n;i++){
        vector<ll>cur=arr[i];
        vector<ll>req(m,-1);
        ll ans=0;
        for(ll j=0;j<m;j++){
            req[cur[j]]=j;
            if(st.find(req)==st.end()) break;
            ans++;
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
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