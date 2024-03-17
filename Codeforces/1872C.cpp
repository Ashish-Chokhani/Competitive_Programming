
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    ll cnt_x=n/x;
    ll cnt_y=n/y;
    ll g=__gcd(x,y);
    ll val=n/g;
    cnt_x-=val;
    cnt_y-=val;
    ll ans=(cnt_x*(2*n+cnt_x-1))/2;
    ans-=(cnt_y*(cnt_y+1))/2;
    cout<<ans<<"\n";
}

int main(){
    ll t,cnt=0;
    cin>>t;
    while(t--){
        cnt++;
        solve();
    }
    return 0;
}