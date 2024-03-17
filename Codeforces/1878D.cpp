#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<ll>l(k),r(k);
    for(ll i=0;i<k;i++){
        cin>>l[i];
        --l[i];
    }
    for(ll i=0;i<k;i++){
        cin>>r[i];
        --r[i];
    }
    ll x;
    cin>>x;
    vector<ll>arr(x);
    for(ll i=0;i<x;i++){
        cin>>arr[i];
        --arr[i];
    }
    vector<ll>ranges(n+1,0);
    vector<pair<ll,ll>>range;
    for(auto it:arr){
        ll ind=lower_bound(l.begin(),l.end(),it)-l.begin();
        if(ind==k || l[ind]!=it) ind--;
        ll a=min(it,l[ind]+r[ind]-it);
        ll b=max(it,l[ind]+r[ind]-it);
        ranges[a]++;
        ranges[b+1]--;
        range.push_back({a,b});
    }
    sort(range.begin(),range.end());
    vector<ll>pre(n+1,0);
    pre[0]=ranges[0];
    for(ll i=1;i<=n;i++){
        pre[i]=ranges[i]+pre[i-1];
    }
    ll cur=0;
    for(ll i=0;i<k;i++){
        if(cur>=range.size()) break;
        ll p=range[cur].first;
        ll q=range[cur].second;
        if(p>=r[i]){
            continue;
        }
        else{
            while(cur<range.size() && range[cur].second<=r[i]) cur++;
            ll start=l[i];
            ll end=r[i];
            vector<char>tmp;
            while(start<=end){
                if(pre[start]&1) tmp.push_back(s[start]);
                start++;
            }
            reverse(tmp.begin(),tmp.end());
            start=l[i];
            end=r[i];
            ll pos=0;
            while(start<=end){
                if(pre[start]&1) s[start]=tmp[pos++];
                start++;
            }

        }
    }
    cout<<s<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    ll cnt=0;
    while (t--)
    {
        solve();
    }
    return 0;
}