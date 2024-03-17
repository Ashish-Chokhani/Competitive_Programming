#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,k,s;
    cin>>n>>k>>s;
    ll maxi=(n-1)*k;
    ll mini=k;
    if(s>maxi || s<mini)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    ll rem=s%k;
    ll q=s/k;
    ll control=1,curr=1;
    for(ll i=1;i<=rem;i++)
    {
        curr=curr+((q+1)*control);
        cout<<curr<<" ";
        control*=-1;
    }
    for(ll i=1;i<=k-rem;i++)
    {
        curr=curr+(q*control);
        cout<<curr<<" ";
        control*=-1;
    }
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
