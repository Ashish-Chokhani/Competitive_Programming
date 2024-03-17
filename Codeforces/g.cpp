#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>buildings(n+1);
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++){
        buildings[i]=i;
    }
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        int pos1=i-k;
        int pos2=i+k;
        //cout<<pos1<<" "<<pos2<<"\n";
        if(mp[pos1] && mp[pos2]){
            cout<<"-1\n"; //Both are occupied
            return;
        }
        if(pos1<=0 && pos2>n){
            cout<<"-1\n";
            return;
        }
        if(!mp[pos1] && pos1>=1){
            ans[i]=pos1;
            mp[pos1]=1;
        }
        else if(!mp[pos2] && pos2<=n){
            ans[i]=pos2;
            mp[pos2]=1;
        }
        else{
            cout<<"-1\n";
            return;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}