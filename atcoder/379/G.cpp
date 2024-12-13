#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> a(n),ans(n,-1);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> v;
    for(int i=n-1;i>=0;i--){
        while(v.size()>0 && a[v.back()]<a[i]){
            ans[v.back()]=i;
            v.pop_back();
        }
        v.push_back(i);
    }

    // for(int i=0;i<n;i++) cout<<ans[i]<<" "<<i<<endl;
    // cout<<endl<<endl;
    vector<pair<int,int>> x;
    for(int i=0;i<n;i++) x.push_back({ans[i],i});

    sort(x.begin(),x.end());
    ordered_set os;

    vector<pair<pair<int,int>,int>> qq;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        qq.push_back({{a-1,b-1},i});
    }

    sort(qq.begin(),qq.end());
    vector<int> anss(q);
    int i=0;
    for(auto [f,ff]:qq){
        int l=f.first,r=f.second;
        // cout<<l<<" "<<r<<endl;
        while(i<n && x[i].first<=l){
            os.insert(x[i].second);
            // cout<<x[i].first<<" "<<x[i].second<<endl;
            i++;
        }
        int xxx=os.size()-os.order_of_key(r+1);
        anss[ff]=xxx;
    }

    for(auto i:anss) cout<<i<<endl;
    

    return 0;
}
