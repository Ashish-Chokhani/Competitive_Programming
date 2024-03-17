#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll maxOverlap(vector<pair<ll,char>>&data){
    ll sz=data.size();
    sort(data.begin(),data.end());
    ll cnt=0,ans=0;
    for(ll i=0;i<sz;i++){
        if(data[i].second=='x') cnt++;
        else cnt--;
        ans=max(ans,cnt);
    }
    return ans;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>intervals(n);
    vector<pair<ll,char>>data1,data2;
    for(ll i=0;i<n;i++){
        cin>>intervals[i].first>>intervals[i].second;
        if(intervals[i].first !=1){
            data1.push_back({intervals[i].first,'x'});
            data1.push_back({intervals[i].second,'y'});
        }
        if(intervals[i].second !=m){
            data2.push_back({intervals[i].first,'x'});
            data2.push_back({intervals[i].second,'y'});
        }
    }
    ll ans=0;
    ans=max(maxOverlap(data1),maxOverlap(data2));
    cout<<ans<<"\n";
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
}