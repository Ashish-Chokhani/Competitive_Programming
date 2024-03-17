#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll a,b;
    cin>>a>>b;
    vector<ll>arr(a),brr(b);
    for(ll i=0;i<a;i++){
        cin>>arr[i];
    }
    for(ll j=0;j<b;j++){
        cin>>brr[j];
    }
    for(ll ans=0;ans<(1LL<<9);ans++){
        ll flag=1;
        for(ll i=0;i<a;i++){
            ll flag2=0;
            for(ll j=0;j<b;j++){
                flag2=flag2|(((arr[i]&brr[j])|ans)==ans);
            }
            flag=flag&flag2;
        }
        if(flag){
            cout<<ans<<"\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
