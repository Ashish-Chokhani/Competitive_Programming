#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>ans(n,0);
    queue<ll>q[2];
    ll sz=0;
    q[s[0]-'0'].push(0);
    for(ll i=1;i<n;i++){
        ll val=s[i]-'0';
        if(q[1-val].size()!=0){
            ll ind=q[1-val].front();
            q[1-val].pop();
            ans[i]=ind;
            q[val].push(ind);
        }
        else{
            sz++;
            q[val].push(sz);
            ans[i]=sz;
        }
    }
    cout<<sz+1<<"\n";
    for(auto it:ans){
        cout<<it+1<<" ";
    }
    cout<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}