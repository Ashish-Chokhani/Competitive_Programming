#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=998244353;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans=0;
    for(ll bit=0;bit<30;bit++){
        ll cur=0,cb=1LL<<bit;
        ll cnt[2],sum[2]; 
        cnt[0]=1;
        cnt[1]=0;
        sum[0]=0;
        sum[1]=0;
        for(ll i=0;i<n;i++){
            if(arr[i]&cb) cur^=1;
            cnt[cur]++;
            sum[cur]+=i+1;
            ll cv=cnt[cur^1]*(i+1)-sum[cur^1];
            cv%=MOD;
            ans+=cv*cb;
            ans%=MOD;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}