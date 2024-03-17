#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fun(ll i,ll lastValue,string &s,ll n){
    if(i==n) return 0;

    ll v1=0,v2=0;
    //v1=(s[i]=='0') + fun(i+1,s[i]-'0',s,n);
    v2=(s[i]=='1' && lastValue==1) + fun(i+1,~((s[i]-'0') & lastValue),s,n);
    return v1+v2+(s[i]=='0');
}

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll val=fun(0,1,s,n)+fun(0,0,s,n);
    ll ans=(n*(n+1))/2-val;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
//1+(2,0)--->(3,1)+(3,0)

//(3,1)--->(4,1)+1+(4,0)

//(4,1)->1
//(4,0)->

//(2,1)