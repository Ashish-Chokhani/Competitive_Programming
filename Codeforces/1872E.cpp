#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ll totXor=0,oneXor=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    string s;
    cin>>s;
    vector<ll>preXor(n,0);
    preXor[0]=arr[0];
    for(ll i=0;i<n;i++){
        if(s[i]=='1') oneXor^=arr[i];
        totXor^=arr[i];
        if(i>=1) preXor[i]=arr[i]^preXor[i-1];
    }
    ll q;t
    cin>>q;
    while(q--){
        ll type;
        cin>>type;
        if(type==2){
            ll val;
            cin>>val;
            if(val==1) cout<<oneXor<<" ";
            else cout<<(totXor^oneXor)<<" ";
        }
        else{
            ll l,r;
            cin>>l>>r;
            --l;
            --r;
            ll val=preXor[r];
            if(l>=1) val^=preXor[l-1];
            oneXor^=val;
        }
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//1 0
//2 8
//3 0
// 4 3
// 5 14

//5 2 4 1 3
//5 3 2 4 1    65