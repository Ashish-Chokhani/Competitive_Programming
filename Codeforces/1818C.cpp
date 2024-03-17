#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll countOnes(ll l,ll r,vector<ll>&pre)
{
    return l>=1 ? pre[r]-pre[l-1]:pre[r];
}
 
void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<ll>check(n,0);
    for(ll i=2;i<n;i++)
    {
        if((arr[i]<=arr[i-1]) && (arr[i-1]<=arr[i-2]))
        check[i-2]=1;
    }
    vector<ll>pre(n,0);
    pre[0]=check[0];
    for(ll i=1;i<n;i++)
    {
        pre[i]=check[i]+pre[i-1];
    }
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        ll low=0,high=r-l+1;
        ll val=r-l+1-countOnes(l,r,pre);
        if(r-l+1<=2)
        {
            cout<<r-l+1<<"\n";
            continue;
        }
        if(r>=1 && check[r-1]==1)
        val++;
        if(check[r])
        val++;
        cout<<val<<"\n";
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
