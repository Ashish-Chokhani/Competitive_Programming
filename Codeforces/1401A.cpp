#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x1,y1,z1,x2,y2,z2;
    cin>>x1>>y1>>z1>>x2>>y2>>z2;
    ll val=min(z1,y2)*2;
    ll left_ones=max(0LL,y2-min(z1,y2));
    y1-=left_ones;
    y1-=x2;
    y1=max(0LL,y1);
    val-=min(y1,z2)*2;
    cout<<val<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    ll cnt=0;
    while(t--){
        solve();
    }
    return 0;
}