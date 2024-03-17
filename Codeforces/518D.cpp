#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> dp(2001,vector<double>(2001,-1));

double findExpectation(int n,int t,double p,int tot)
{
    if(n<=0 || t<=0)
    return (tot-n);

    if(dp[n][t]!=-1)
    return dp[n][t];

    double move=p*findExpectation(n-1,t-1,p,tot);

    double dont_move=(1-p)*findExpectation(n,t-1,p,tot);

    return dp[n][t]=(move+dont_move);
}

void solve()
{
int n,t;
double p;
cin>>n>>p>>t;
cout<<setprecision(12)<<findExpectation(n,t,p,n)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}