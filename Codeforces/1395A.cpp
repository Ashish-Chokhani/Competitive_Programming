#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll findVal(ll a,ll b,ll c,ll d){
    ll cnt_odd=0;
    cnt_odd+=a&1;
    cnt_odd+=b&1;
    cnt_odd+=c&1;
    cnt_odd+=d&1;
    return cnt_odd;
}

void solve(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll cnt_odd=findVal(a,b,c,d);
    ll mini=min(a,min(b,c));
    if(cnt_odd<=1){
        cout<<"Yes\n";
        return;
    }
    if(mini>0){
        a--;
        b--;
        c--;
        d+=3;
        cnt_odd=findVal(a,b,c,d);
        if(cnt_odd<=1){
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
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
