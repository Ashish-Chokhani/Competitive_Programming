#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll findSum(ll n){
    ll s=0;
    while(n>0){
        s+=n%10;
        n/=10;
    }
    return s;
}

void solve()
{
    ll n;
    string s;
    cin>>n;
    cin>>s;
    stack<ll>zeros;
    ll cnt=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='0'){
            zeros.push(i);
            cnt++;
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(i>=cnt){
            cout<<"-1 ";
            continue;
        }
        ll val=0;
        val=zeros.top();
        zeros.pop();
        ans+=n-1-val;
        cout<<ans-i<<" ";
        ans=ans-i;
    }
    cout<<"\n";
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