#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll Sum(ll l,ll,r,vector<ll>&pre)
{
    if(l==0)
    return pre[r];
    return pre[r]-pre[l-1];
}

void solve()
{
    string s;
    cin>>s;
    ll n=s.length();
    ll w,m;
    cin>>w>>m;
    vector<ll>pre(n,0);
    pre[0]=s[0]-'0';
    for(ll i=1;i<n;i++)
    {
        pre[i]=s[i]-'0' + pre[i-1];
    }
    vector<ll>adj(9,-1);
    for(ll i=0;i+w-1<n;i++)
    {
        ll val=Sum(i,i+w-1,pre)%9;
        if(adj[val]==-1)
        adj[val]=i;
    }
    vector<pair<ll,ll>>arr;
    for(ll i=0;i<9;i++)
    {
        if(adj[i]!=-1)
        arr.push_back(adj[i],i);
    }
    sort(arr.begin(),arr.end());
    while(m--)
    {
        ll l,r,k;
        cin>>l>>r>>k;
        --l;
        --r;
        ll b=Sum(l,r,pre)%9;
        int flag=1;
        for(ll i=0;i<arr.size() && flag;i++)
        {
            ll L1=arr[i].first;
            ll a=arr[i].second;
            for(ll j=0;j<arr.size() && flag;j++)
            {
                if(i==j)
                continue;
                ll L2=arr[j].first;
                ll c=arr[j].second;
                if((((a*b)%9)+c)%9==k)
                {
                    cout<<L1+1<<" "<<L2+1<<"\n";
                    flag=0;
                }
            }
        }
        if(!flag)
        {
            cout<<"-1 -1\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}
