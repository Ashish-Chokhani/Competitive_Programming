#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll m,k,a1,ak;
    cin>>m>>k>>a1>>ak;
    ll ans=m;
    ll val=min(ak,m/k);
    m-=(k*val);
    ll rem=m%k;
    ll v1=min(a1,rem);
    m-=v1;
    a1-=v1;
    ll v=a1/k;
    m-=v*k;
    m=max(0LL,m);
    cout<<m/k+m%k<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}