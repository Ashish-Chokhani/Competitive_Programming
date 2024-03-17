#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int j=0;
    ll ans=1;
    for(ll i=1;i<n;i++)
    {
        if(arr[i]==arr[j])
        {
            while(i<n && arr[i]==arr[j])
            i++;
            i--;
        }
        else if(i<n && arr[i]>arr[j])
        {
            while(i<n && arr[i]>=arr[i-1])
            i++;
            i--; 
            j=i;
            ans++;
        }
        else if(i<n && arr[i]<arr[j])
        {
            while(i<n && arr[i]<=arr[i-1])
            i++;
            i--; 
            j=i;
            ans++;
        }
    }
    cout<<ans<<"\n";
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
