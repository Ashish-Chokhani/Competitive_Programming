#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll findMEX(ll a,ll b,ll c){
    map<ll,ll>mp;
    mp[a]=mp[b]=mp[c]=1;
    for(ll i=0;i<=3;i++){
        if(!mp[i])
        return i;
    }
    return 0;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    string s;
    cin>>s;
    vector<vector<vector<ll>>>freq(3,vector<vector<ll>>(3));
    for(ll i=0;i<n;i++){
        if(s[i]=='M')
        freq[0][arr[i]].push_back(i);
        else if(s[i]=='E')
        freq[1][arr[i]].push_back(i);
        else
        freq[2][arr[i]].push_back(i);
    }
    ll ans=0;
    for(ll i=0;i<=2;i++){
        for(ll j=0;j<=2;j++){
            for(ll k=0;k<=2;k++){
                ll val=findMEX(i,j,k);
                ll cnt=0;
                for(ll x=0;x<freq[1][j].size();x++){
                    ll ind=freq[1][j][x];
                    ll l=lower_bound(freq[0][i].begin(),freq[0][i].end(),ind)-freq[0][i].begin();
                    ll r=lower_bound(freq[2][k].begin(),freq[2][k].end(),ind+1)-freq[2][k].begin();
                    cnt+=l*(freq[2][k].size()-r);
                }
                ans+=val*cnt;
            }
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    solve();
    return 0;
}