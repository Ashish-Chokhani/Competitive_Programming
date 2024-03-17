#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string l,r;
    cin>>l>>r;
    if(l==r)
    {
        cout<<r<<"\n";
        return;
    }
    if(l[0]!=r[0])
    {
        for(ll i=1;i<=n;i++)
        cout<<"1";  
        cout<<"\n";
        return;    
    }
    ll pt=0;
    while(pt<n && l[pt]==r[pt])
    pt++;
    bool bad=true;
    pt++;
    while(pt<n)
    {
        bad&=(l[pt]=='1');
        bad&=(r[pt]=='0');
        pt++;
    }
    if(!bad)
    r[n-1]='1';
    cout<<r<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}