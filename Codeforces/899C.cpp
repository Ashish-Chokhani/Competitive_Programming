#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    ll totSum=0;
    vector<ll>arr(n+1);
    ll firstPos=-1;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>0) totSum+=arr[i];
        if(firstPos==-1 && arr[i]>0) firstPos=i;
    }
    if(firstPos==0 || firstPos>=2){
        cout<<totSum<<"\n";
        return;
    }
    if(firstPos==-1){
        cout<<"0\n";
        return;
    }
    ll val=max(0LL,totSum-arr[firstPos]);
    for(ll i=0;i<firstPos;i++){
        val=max(val,totSum+arr[i]);
    }
    cout<<val<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    ll cnt=0;
    cin >> t;
    while (t--)
    {
        cnt++;
        solve();
    }
    return 0;
}