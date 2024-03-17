#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool isPowerof2(ll n){
    ll val=log2(n);
    return pow(2,val)==n;
}

int whatPower(ll n){
    return log2(n);
}

void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>arr(n),queries(q);
    int bal=0;
    set<ll>st;
    for(auto &x:arr){
        cin>>x;
        if(isPowerof2(x)){
            st.insert(whatPower(x));
        }
    }
    for(auto &x:queries){
        cin>>x;
    }
    for(auto it:queries){
        if(st.empty()) break;
        int maxi=*(--st.end());
        if(maxi<it) continue;
        for(ll iter:st){
            if(iter>=it){
                st.erase(iter);
            };
        }
        // for(auto &val:arr){
        //     ll z=pow(2,it);
        //     if(val % z==0){
        //         val+=pow(2,it-1);
        //     }
        // }
    }
    for(auto it:arr){
        cout<<it<<" ";
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