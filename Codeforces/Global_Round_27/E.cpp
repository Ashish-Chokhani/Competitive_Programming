#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin >> v[i];

    vector<int> arr(2*k+1, n);
    vector<int> pref(2*k+2, 0);
    for (int i=0; i<n/2; i++) {
        int sum = v[i]+v[n-i-1];
        arr[sum] -= 1;
        int l = 1+min(v[i], v[n-i-1]);
        int r = k+max(v[i], v[n-i-1]);
        pref[l] += 1;
        pref[r+1] -= 1;
    }

    for (int i=1; i<2*k+1; i++) {
        pref[i] += pref[i-1];
        arr[i] -= pref[i];
    }
    for(int i=0;i<2*k+1;i++) cout<<pref[i]<<" ";
    cout<<"\n";
    for(int i=0;i<2*k+1;i++) cout<<arr[i]<<" ";
    cout<<"\n";
    int ans = 2*n;
    for (int i=0; i<2*k+1; i++)
        ans = min(ans, arr[i]);
    cout<<ans<<"\n";
}

int main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}