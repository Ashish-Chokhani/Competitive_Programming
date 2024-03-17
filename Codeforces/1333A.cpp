#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>suf(n+1,0);
    for(ll i=n-1;i>=0;i--){
        suf[i]=max(arr[i],suf[i]);
    }
    for(ll i=0;i<n;i++){
        if(m<=0) break;
        if(arr[i]==0) continue;
        arr[i]--;
        m--;
        if(m<=0) break;
        if(suf[i+1]<m){
            ll red=min(m,min(arr[i],suf[i+1]));
            arr[i]-=red;
            m-=red;
        }
    }
    for(auto it:arr){
        cout<<it<<" ";
    }
    ll val=-2/3;
    cout<<val<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
