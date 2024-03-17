#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
 
void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"1"<<endl;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef Cleverfox
    freopen("input.txt","r",stdin);
    freopen("output_brute.txt","w",stdout);
    freopen("error_brute.txt","w",stderr);
    #endif
    
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}