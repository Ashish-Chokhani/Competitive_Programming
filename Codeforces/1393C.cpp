#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(ll dist,priority_queue<ll>pq){
    while(!pq.empty()){
        if(pq.size()<dist){
            while(!pq.empty()){
                ll val=pq.top();
                pq.pop();
                if(val>=2) return false;
            }
            return true;
        }
        vector<ll>freq;
        for(ll i=0;i<dist;i++){
            ll val=pq.top();
            pq.pop();
            freq.push_back(val);
        }
        for(ll i=0;i<dist;i++){
            ll val=freq[i];
            if(val>1) pq.push(val-1);
        }
    }
    return true;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>arr(n);
    map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    priority_queue<ll>pq;
    for(auto it:mp){
        pq.push(it.second);
    }
    ll l=1,r=pq.size()+1,ans;
    while(l<=r){
        ll mid=(l+r)/2;
        if(isPossible(mid,pq)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans-1<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
