#include <bits/stdc++.h>
using namespace std;

void solve()
{
    //Assume u r given a vector arr
    vector<int>ans;
    int cnt0=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            cnt0++;
        }
        else{
            ans.push_back(arr[i]);
        }
    }
    while(cnt0--){
        ans.push_back(0);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main()
{
    solve();
    return 0;
}