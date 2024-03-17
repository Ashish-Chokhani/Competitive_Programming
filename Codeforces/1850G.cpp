#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>>arr(n);
    unordered_map<ll,ll>left,right,hor,ver;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        arr[i].first=x;
        arr[i].second=y;
        left[x-y]++;
        right[x+y]++;
        hor[y]++;
        ver[x]++;
    }
    ll ans=0;
    for(auto it:arr){
        ll x=it.first;
        ll y=it.second;
        ans+=left[x-y]-1;
        ans+=right[x+y]-1;
        ans+=hor[y]-1;
        ans+=ver[x]-1;
    }
    cout<<ans<<"\n";
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