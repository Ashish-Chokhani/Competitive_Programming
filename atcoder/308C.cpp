#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>A(n),B(n);
    for(ll i=0;i<n;i++){
        cin>>A[i]>>B[i];
    }
    vector<ll>ind(n,0);
    iota(ind.begin(),ind.end(),0);
    sort(ind.begin(),ind.end(),[&](ll a,ll b){
        if(A[a]*(A[b]+B[b])==A[b]*(A[a]+B[a])) return a<b;
        return A[a]*(A[b]+B[b])>A[b]*(A[a]+B[a]);
    });
    for(ll i=0;i<n;i++){
        cout<<ind[i]+1<<" ";
    }
    cout<<"\n";
}

int main()
{
    solve();
    return 0;
}