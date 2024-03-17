#include<bits/stdc++.h>
using namespace std;

bool isPossible(int sz,vector<int>&arr,int k,int n){
    int cntPlace=1;
    int dist=0;
    for(int i=1;i<n;i++){
        dist+=arr[i]-arr[i-1];
        if(dist>=sz){
            cntPlace++;
            dist=0;
        }
    }
    return cntPlace>=k;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    int maxi=-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    int l=0,r=maxi,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(isPossible(mid,arr,k,n)){
            l=mid+1;
            ans=max(ans,mid);
        }
        else{
            r=mid-1;
        }
    }
    //cout<<isPossible(3,arr,3,n)<<"\n";
    cout<<ans<<"\n";
}

int main(){
    solve();
    return 0;
}