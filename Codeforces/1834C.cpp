#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    if(s==t){
        cout<<"0\n";
        return;
    }
    ll diff1=0,diff2=0;
    for(ll i=0;i<n;i++){
        diff1+=s[i]!=t[i];
    }
    if(diff1%2==0) diff1=2*diff1;
    else diff1=2*diff1-1;
    reverse(t.begin(),t.end());
    for(ll i=0;i<n;i++){
        diff2+=s[i]!=t[i];
    }
    if(diff2%2!=0) diff2=diff2*2;
    else diff2=max(2LL,2*diff2-1);
    cout<<min(diff1,diff2)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    ll cnt=0;
    while(t--){ 
        solve();
    }
}