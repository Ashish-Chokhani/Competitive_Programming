#include <bits/stdc++.h>
using namespace std;

struct Info {
    long long int x, y, t;
    double p;
    Info(int _x, int _y, int _t, double _p) : x(_x), y(_y), t(_t), p(_p) {}
};

int32_t main() {
    int n;
    cin >> n;
    vector<Info> arr;
    for (int i = 0; i < n; i++) {
        long long int x, y, t;
        double p;
        cin >> x >> y >> t >> p;
        arr.emplace_back(x, y, t, p); 
    }
    vector<int>order(n,0);
    iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&](int i,int j){
        return arr[i].t<arr[j].t;
    });
    vector<double>dp(n);
    for(int i=0;i<n;i++){
        dp[i]=arr[order[i]].p;
        double val=0.0;
        for(int j=0;j<i;j++){
            long long int x1=arr[order[j]].x,y1=arr[order[j]].y,x2=arr[order[i]].x,y2=arr[order[i]].y;
            long long int t1=arr[order[j]].t,t2=arr[order[i]].t;
            if(hypot(x2-x1,y2-y1)<=(t2-t1)) val=max(val,dp[j]);
        }
        dp[i]+=val;
    }
    cout<<setprecision(12)<<*max_element(dp.begin(),dp.end())<<"\n";
}