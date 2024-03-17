#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,p,q,r,s;
    cin>>n>>p>>q>>r>>s;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll i=p-1,j=r-1;
    while(i<q && j<s){
        swap(arr[i],arr[j]);
        i++;
        j++;
    }
    for(auto it:arr) cout<<it<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}