#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>LEFT(2024),RIGHT(2024);
vector<ll>sum(2024,0);

void fun()
{
    LEFT[0]=RIGHT[0]=1;
    ll l=1,r=2;
    sum[0]=1;
    for(ll i=1;i<=2023;i++)
    {
        LEFT[i]=LEFT[i-1]+l;
        l++;
        RIGHT[i]=RIGHT[i-1]+r;
        r++;
        for(ll j=LEFT[i];j<=RIGHT[i];j++)
        sum[i]+=j*j;
    }
}

ll Sum(ll val)
{
    return (val*(val+1)*(2*val+1))/6;
}

void solve()
{
    ll n;
    cin>>n;
    ll index=lower_bound(LEFT.begin(),LEFT.end(),n)-LEFT.begin();
    if(LEFT[index]!=n)
    index--;
    ll ans=n*n;
    ll row=index-1;
    ll sub=index+1;
    ll start=1;
    while(row>=0)
    {
        ll l=n-sub;
        n=l;
        ll r=l+start;
        l=max(l,LEFT[row]);
        r=min(r,RIGHT[row]);
        ans+=Sum(r)-Sum(l-1);
        sub--;
        row--;
        start++;
    }
    cout<<ans<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    fun();
    while(t--)
    {
    solve();
    }
    return 0;
}