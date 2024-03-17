#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define p 1000000007

ll binexp(ll a, ll b, ll m)
{
    if (b == 0)
        return 1ll;
    if (b == 1)
        return a % m;
    if (b % 2)
        return (a * binexp(a, b - 1, m)) % m;
    return binexp((a * a) % m, b / 2, m);
}

// To calculate modular inverse
ll mod_inv(ll x)
{
    return binexp(x, p - 2, p);
}

void solve()
{
   ll n;
   cin>>n;
   vector<ll>pro(n);
   for(ll i=0;i<n;i++)
   {
    ll x,y;
    cin>>x>>y;
    pro[i]=x*mod_inv(y);
    pro[i]%=p;
   }
   vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
   for(ll i=0;i<=n;i++)
   {
    cin>>dp[0][i];
   }
   for(ll i=1;i<=n;i++)
   {
    for(ll j=0;j<=n-i;j++)
    {
        dp[i][j]=(dp[i-1][j+1]*pro[i-1])%p + (dp[i-1][max(0LL,j-1)]*(p- pro[i-1] +1))%p;
        dp[i][j]%=p;
    }
   }
   for(ll i=1;i<=n;i++)
   {
    cout<<dp[i][0]<<" ";
   }
   cout<<"\n";
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
