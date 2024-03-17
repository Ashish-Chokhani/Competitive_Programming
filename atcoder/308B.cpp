#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,m;
    cin >> n >>m;
    vector<string>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<string>C(m);
    for(ll i=0;i<m;i++){
        cin>>C[i];
    }
    map<string,ll>mp;
    ll p;
    for(ll i=0;i<m+1;i++){
        ll val;
        cin>>val;
        if(i==0)
        p=val;
        else
        mp[C[i-1]]=val;
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(!mp[arr[i]])
        ans+=p;
        else
        ans+=mp[arr[i]];
    }
    cout<<ans<<"\n";
}

int main()
{
    solve();
    return 0;
}