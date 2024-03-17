#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    int onlyOnce=1;
    ll i=1,j=0;
    while(i<=n){
        int flag=1;
        while(j<i){
            if(flag){
                flag=0;
                j++;
                continue;
            }
            if(arr[j]<arr[j-1]){
                cout<<"NO\n";
                return;
            }
            j++;
        }
        i=i*2;
        if(i>=n){
            if(onlyOnce){
                onlyOnce=0;
                i=n;
            }
        }
    }
    cout<<"YES\n";
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