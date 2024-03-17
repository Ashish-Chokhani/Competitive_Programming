#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(ll mid,vector<ll>&A,vector<ll>&B){
    ll n=A.size(),m=B.size(),canBuy=0,canSell=0;
    for(ll i=0;i<n;i++){
        if(A[i]<=mid) canSell++;
    }
    for(ll i=0;i<m;i++){
        if(mid<=B[i]) canBuy++;
    }
    return canSell>=canBuy;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>A(n),B(m);
    for(ll i=0;i<n;i++){
        cin>>A[i];
    }
    for(ll i=0;i<m;i++){
        cin>>B[i];
    }
    ll l=1,r=1e9+2,ans;
    while(l<=r){
        ll mid=(l+r)/2;
        if(isPossible(mid,A,B)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
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