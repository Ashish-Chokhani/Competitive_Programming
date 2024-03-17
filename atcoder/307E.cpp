#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

#define MOD 998244353

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n+1),b(n+1);
    a[1]=m;
    b[1]=0;
    for(int i=2;i<=n;i++){
        a[i]=b[i-1]%MOD;
        b[i]=((b[i-1]%MOD*(m-2)%MOD)%MOD + ((a[i-1]%MOD) * (m-1)%MOD)%MOD)%MOD;
    }
    cout<<b[n]<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}