#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(ll nelm,ll d,vector<ll>&a,vector<ll>&b){
    ll n1=a.size();
    ll n2=b.size();
    if(nelm>n1) return false;
    ll req=max(0LL,(nelm-1)*d);
    if(n2+n1-nelm<req) return false;
    return true;
}

ll value(ll nelm,ll d,vector<ll>&a,vector<ll>&b){
    ll n1=a.size();
    ll n2=b.size();
    ll val=0;
    for(ll i=0;i<nelm;i++){
        val+=a[i];
    }
    multiset<ll>st;
    for(ll i=0;i<n2;i++){
        st.insert(b[i]);
    }
    ll leave=max(0LL,((nelm-1)*d)-n1+nelm),c=0;
    for(auto it:st){
        if(c>=leave) val+=it;
        c++;
    }
    return val;
}

void solve()
{
    ll n,d,m;
    cin>>n>>d>>m;
    vector<ll>a,b;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x>m) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());
    ll ans=0;
    ll l=0,r=n;
    while(l<=r){
        ll mid=(l+r)/2;
        if(isPossible(mid,d,a,b)){
            if(value(mid,d,a,b)==77) cout<<mid<<"\n";
            ans=max(ans,value(mid,d,a,b));
            l=mid+1;
        }
        else 
        r=mid-1;
    }
    for(auto it:a) cout<<it<<" ";
    cout<<"\n";
    for(auto it:b) cout<<it<<" ";
    cout<<"\n";
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
