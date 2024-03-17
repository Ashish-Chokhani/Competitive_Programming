#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    set<ll>st;
    map<ll,ll>freq;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        st.insert(arr[i]);
        freq[arr[i]]++;
    }
    ll sz=st.size();
    if(sz>=3){
        cout<<"NO\n";
        return;
    }
    if(sz==1){
        cout<<"YES\n";
        return;
    }
    ll ele1=*st.begin();
    ll ele2=*(--st.end());
    // ll ele1=0,ele2=0;
    cout<<(abs(freq[ele1]-freq[ele2])<=1 ? "YES\n" : "NO\n");
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