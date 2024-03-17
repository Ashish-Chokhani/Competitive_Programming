#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void Colour(ll i,ll j,vector<ll>&color,vector<ll>&a)
{
    for(ll k=i;k<=j;k++)
    {
        color[a[k]]=1;
    }
}

ll sum(ll l,ll r,vector<ll>&pre)
{
    if(l==0)
    return pre[r];
    return pre[r]-pre[l-1];
}

bool isPossible(ll mid,vector<ll>&pre,vector<pair<ll,ll>>&arr)
{
    for(auto it:arr)
    {
        if(sum(it.first,it.second,pre)*2>it.second-it.first+1)
        return true;
    }
    return false;
}


void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>arr(m);
    for(ll i=0;i<m;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        --arr[i].first;
        --arr[i].second;
    }
    ll q;
    cin>>q;
    vector<ll>a;
    while(q--)
    {
        ll x;
        cin>>x;
        --x;
        a.push_back(x);
    }
    ll ans=-1,l=1,r=a.size();
    while(l<=r)
    {
        ll mid=(l+r)/2;
        vector<ll>color(n,0),pre(n,0);
        Colour(0,mid-1,color,a);
        pre[0]=color[0];
        for(ll i=1;i<n;i++)
        {
            pre[i]=color[i]+pre[i-1];
        }
        if(isPossible(mid,pre,arr))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
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
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
