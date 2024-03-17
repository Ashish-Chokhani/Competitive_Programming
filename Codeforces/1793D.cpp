#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll,ll>mp1,mp2;

bool isLeft(ll max1,ll max2,ll cur1,ll cur2)
{
    return max(max1,max2)<min(cur1,cur2);
}

bool isRight(ll min1,ll min2,ll cur1,ll cur2)
{
    return min(min1,min2)>max(cur1,cur2);
}
bool isbetween(ll min1,ll min2,ll max1,ll max2,ll cur1,ll cur2)
{
    return (min(min1,min2)>min(cur1,cur2)) && (max(max1,max2)<max(cur1,cur2));
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>p(n),q(n);
    for(ll i=0;i<n;i++)
    {
        cin>>p[i];
        mp1[p[i]]=i;
    }
    mp1[n+1]=n;
    for(ll i=0;i<n;i++)
    {
        cin>>q[i];
        mp2[q[i]]=i;
    }
    mp2[n+1]=n;
    vector<pair<ll,ll>>p1(n+2),q1(n+2);
    ll maxi=mp1[1],mini=mp1[1];
    for(ll i=2;i<=n+1;i++)
    {
        maxi=max(maxi,mp1[i-1]);
        mini=min(mini,mp1[i-1]);
        p1[i]={maxi,mini};
    }
    maxi=mp2[1],mini=mp2[1];
    for(ll i=2;i<=n+1;i++)
    {
        maxi=max(maxi,mp2[i-1]);
        mini=min(mini,mp2[i-1]);
        q1[i]={maxi,mini};
    }
    ll ans=0;
    ll v1=min(mp1[1],mp2[1]);
    ll v2=n-max(mp1[1],mp2[1])-1;
    ll v3=max(mp1[1],mp2[1])-v1-1;
    ans+=v1*(v1+1)/2 + v2*(v2+1)/2 +v3*(v3+1)/2;
    for(ll i=2;i<=n+1;i++)
    {
        ll maxi1=p1[i].first;
        ll maxi2=q1[i].first;
        if(isLeft(maxi1,maxi2,mp1[i],mp2[i]))
        {
            ll l=min(p1[i].second,q1[i].second);
            ll r=max(p1[i].first,q1[i].first);
            ans+=(l+1)*(min(mp1[i],mp2[i])-r);
        }
        ll min1=p1[i].second;
        ll min2=q1[i].second;
        if(isRight(min1,min2,mp1[i],mp2[i]))
        {
            ll l=min(p1[i].second,q1[i].second);
            ll r=max(p1[i].first,q1[i].first);
            ans+=(n-r)*(l-max(mp1[i],mp2[i]));
        }
        if(isbetween(min1,min2,maxi1,maxi2,mp1[i],mp2[i]))
        {
            ll l=min(p1[i].second,q1[i].second);
            ll r=max(p1[i].first,q1[i].first);
            ans+=(max(mp1[i],mp2[i])-r)*(l-min(mp1[i],mp2[i]));
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
