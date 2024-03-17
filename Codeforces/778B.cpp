#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<string>arr(n);
    for(ll i=0;i<n;i++)
    {
        getline(cin,arr[i]);
    }
    for(ll i=0;i<n;i++)
    {
        cout<<arr[i]<<"\n";
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
