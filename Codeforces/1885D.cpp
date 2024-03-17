#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

void solve()
{
    ll n,m;
    cin>>n>>m;
    n=n%m;
    if((m%(m-n))!=0){
        cout<<"-1\n";
        return;
    }
    ll val=m/(m-n);
    if(ceil(log2(val))!=floor(log2(val))){
        cout<<"-1\n";
        return;
    }
    ll x=log2(val);
    ll y=m/2;
    if(y<x){
        cout<<"-1\n";
        return;
    }
    cout<<(y/pow(2,x-1))+2*y*(x-1)<<"\n";
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
}