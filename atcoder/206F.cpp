#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

bool isPossible(ll i,ll l,ll r,ll turn,vector<pair<ll,ll>>&arr,ll n){
    if(i==0)
    {
    if(turn==0)
    return (arr[i].second<l || arr[i].first>r);
    else
    return !(arr[i].second<l || arr[i].first>r);
    }
    bool pick=false;
    if(arr[i].second<l || arr[i].first>r)
    pick=isPossible(n-1,min(l,arr[i].first),max(r,arr[i].second),!turn,arr,n);
    bool notPick=isPossible(i-1,l,r,turn,arr,n);
    bool flag=false;
    if(turn==0)
    flag= pick | notPick;
    else
    flag= !(pick | notPick);
    return flag;
}
 
void solve()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        --arr[i].second;
    }
    // sort(arr.begin(),arr.end());
    if(isPossible(n-1,100,0,0,arr,n))
    cout<<"Alice\n";
    else
    cout<<"Bob\n";
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
}