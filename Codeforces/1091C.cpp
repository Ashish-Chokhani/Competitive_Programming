#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>factors;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            factors.push_back(i);
            if(n/i!=i)
            factors.push_back(n/i);
        }
    }
    vector<ll>ans;
    for(auto it:factors)
    {
        ll l=n/it;
        ans.push_back(l+(((l*(l-1))/2)*it));
    }
    sort(ans.begin(),ans.end());
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
