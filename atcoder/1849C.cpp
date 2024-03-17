#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll findLastZero(ll l,ll r,vector<ll>&zeros){
    ll res=-1;
    ll low=0,high=zeros.size()-1;
    while(low<=high){
        ll mid=(low+high)/2;
        if(zeros[mid]>=l && zeros[mid]<=r){
            res=zeros[mid];
            low=mid+1;
        }
        else if(zeros[mid]>r) high=mid-1;
        else low=mid+1;
    }
    return res;
}

ll findFirstOne(ll l,ll r,vector<ll>&ones){
    ll res=lower_bound(ones.begin(),ones.end(),l)-ones.begin();
    ll sz=ones.size();
    if(res==sz || ones[res]>r) return -1;
    return ones[res];
}


void solve()
{
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<ll>zeros,ones;
    for(ll i=0;i<n;i++){
        if(s[i]=='0') zeros.push_back(i);
        else ones.push_back(i);
    }
    ll isSorted=0;
    set<pair<ll,ll>>st;
    while(m--){
        ll l,r;
        cin>>l>>r;
        --l;
        --r;
        ll first=findFirstOne(l,r,ones);
        ll last=findLastZero(l,r,zeros);
        if(first>=last || first==-1 || last==-1){ //already sorted
        isSorted=1;
        }
        else{
            st.insert({first,last});
        }
    }
    cout<<st.size()+isSorted<<"\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}