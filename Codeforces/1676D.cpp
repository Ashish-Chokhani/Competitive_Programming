#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n,m;
    cin>>n>>m;
    vector<vector<long long int>>arr(n,vector<long long int>(m));
    map<long long int,long long int> rd,ld;
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<m;j++)
        {
        cin>>arr[i][j];
        rd[(n+m-1)-(i+j)] += arr[i][j];
        ld[m+(i-j)] += arr[i][j];
        }
    }
    long long int maxi=-1;
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<m;j++)
        {
        long long int sum=rd[(n+m-1)-(i+j)] + ld[m+(i-j)] -arr[i][j];
        maxi=max(sum,maxi);
        }
    }
    cout<<maxi<<"\n";

}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}