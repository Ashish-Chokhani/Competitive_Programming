#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,a,b;
    cin>>n>>a>>b;
    char s[2*n+2];
    for(ll i=0;i<n;i++){
        cin>>s[i];
    }
    for(ll j=n;j<2*n;j++){
        s[j]=s[j-n];
    }
    ll ans=1e17;
    for(ll k=0;k<n;k++){
        ll w=a*k;
        for(ll i=0;i<n-1-i;i++){
            if(s[i+k]!=s[n-1-i+k])
            w+=b;
        }
        ans=min(ans,w);
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