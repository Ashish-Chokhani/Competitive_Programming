#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    map<ll,ll>mp;
    ll cntSquares=0,cntrectangels=0;
    for(ll i=0;i<n;i++){
        ll side;
        cin>>side;
        mp[side]++;
        if(freq[side]>=4){
            cntSquares++;
            freq[side]-=4;
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
