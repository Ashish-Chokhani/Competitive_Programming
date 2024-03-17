#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> a,b;
    int s_a=0,s_b=1;
    while(s_a<n)
    {
        a.push_back(9);
        s_a+=9;
    }
    for(int i=0;i<a.size();i++)
    {
        b.push_back(0);
    }
    b[0]=1;
    while(s_b<n)
    {
        b.push_back(9);
        s_b+=9;
    }
    reverse(b.begin(),b.end());
    for(auto it:a)
    {
        cout<<it;
    }
    cout<<" ";
    for(auto it:b)
    {
        cout<<it;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
