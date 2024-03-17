#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll countOnes(vector<ll>&arr,ll m)
{
    ll cnt=0;
    for(ll i=0;i<m;i++)
    {
        cnt+=arr[i]==1;
    }
    return cnt;
}
 
ll countConsecutive(vector<ll>&arr,ll m)
{
    ll j=0;
    ll tot=0;
    while(j<m)
    {
        if(arr[j]==1)
        {
            ll len=0;
            while(j<m && arr[j]==1)
            {
                len++;
                j++;
            }
            tot+=len/2;
        }
        j++;
    }
    return tot;
}

ll countConsecutives(vector<ll> &arr, ll m)
{
    ll j = 0;
    ll tot = 0,len=0;
    while (j < m)
    {
        if(j>=1 && arr[j]==1 && arr[j-1]==1)
        {
            tot+=len/2;
            len=0;
        }
        len++;
        j++;
    }
    tot+=len/2;
    return tot;
}

 
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> arr(n,vector<ll>(m));
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(ll j=0;j<m;j++)
        {
            arr[i][j]=s[j]-'0';
        }
    }
    ll mini=0,maxi=0;
    for(ll i=0;i<n;i++)
    {
        ll cnt_ones = countOnes(arr[i], m);
        ll cons = countConsecutive(arr[i], m);
        ll cons2 = countConsecutives(arr[i], m);
        ll mini_val = min(m / 4, cons);
        mini += cnt_ones - mini_val;
        ll maxi_val = min(m / 4, cons2);
        ll rem_val = m/4 - maxi_val;
        maxi += cnt_ones - rem_val;
    }
    cout<<mini<<" "<<maxi<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
