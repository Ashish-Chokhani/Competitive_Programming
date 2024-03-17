#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y)
{
    long long res = 1;
    while (y)
    {
        if (y & 1)
        {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

ll Find(ll n)
{
    ll cnt=0,dup=n;
    while(dup>0)
    {
        dup=dup/10;
        cnt++;
    }
    if(cnt==0)
    return 0;
    ll ans=(exp(10,cnt-1)-1)/9LL;
    ll mask=exp(10,cnt-1);
    ll g=min(mask,n-mask+1);
    return ans+g;
}

ll findOnes(ll l,ll r)
{
    return Find(r)-Find(l-1);
}

vector<vector<double>>dp(1001,vector<double>(1001,-1));

double findWays(ll index,ll cnt,ll req,vector<ll>&arr,vector<ll>&sz)
{
    if(index<0)
    {
        return cnt>=req?1:0;
    }
    if(dp[index][cnt]!=-1)
    return dp[index][cnt];
    double pick=0,not_pick=0;
    double z=(double)arr[index]/sz[index];
    if(arr[index]>0)
    pick=z*findWays(index-1,cnt+1,req,arr,sz);
    not_pick=(1-z)*findWays(index-1,cnt,req,arr,sz);
    return dp[index][cnt]=pick+not_pick;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll>arr(n),size(n);
    for(int i=0;i<n;i++)
    {
        ll l,r;
        cin>>l>>r;
        arr[i]=findOnes(l,r);
        size[i]=r-l+1;
    }
    int k;
    cin>>k;
    ll c=n*k;
    double y=(double)c/100;
    ll req=ceil(y);
    double ans=findWays(n-1,0,req,arr,size);
    cout<<setprecision(12)<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
