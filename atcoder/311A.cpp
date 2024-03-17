#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>occur(3,0);
    for(ll i=0;i<n;i++){
        occur[s[i]-'A']=1;
        ll sum=occur[0]+occur[1]+occur[2];
        if(sum==3){
            cout<<i+1<<"\n";
            break;
        }
    }
}

int main()
{
    solve();
    return 0;
}