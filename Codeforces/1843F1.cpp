#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>max_suf(n+1,0),max_mx(n+1,0),min_suf(n+1,0),min_mx(n+!,0);
    max_suf[0]=1;
    max_mx[0]=1;
    ll cur=0;
    while(n--)
    {
        char c;
        cin>>c;a
        if(c=='+'){
            ll v,x;
            cin>>v>>x;
            --v;
            cur++;
            max_suf[cur]=max(0LL,max_suf[v] + x);
            max_mx[cur]=max(max_mx[v],max_suf[cur]);
            min_suf[cur]=min(0LL,min_suf[v] + x);
            min_mx[cur]=min(min_mx[v],min_suf[cur]);
        }
        else{
            ll u,v,k;
            cin>>u>>v>>k;
            --u;
            --v;
            if(k>=min_mx[v] && k<=max_mx[v])
            cout<<"YES\n";
            else
            cout<<"NO\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}
