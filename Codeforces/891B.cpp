#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll>>arr(n),shift(n);
    set<int>st;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin>>x;
        arr[i]={x,i};
        st.insert(arr[i].first);
    }
    if(st.size()==1)
    {
        cout<<"-1\n";
        return;
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        shift[i].first=arr[(i+1)%n].first;
        shift[i].second=arr[i].second;
    }
    vector<ll>b(n);
    for(ll i=0;i<n;i++)
    {
        b[shift[i].second]=shift[i].first;
    }
    for(ll i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
}

int main()
{
    solve();
    return 0;
}
