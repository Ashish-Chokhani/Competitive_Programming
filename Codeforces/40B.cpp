#include <bits/stdc++.h>
using namespace std;

long long int countColors(long long int n,long long int m)
{
    long long int count=0;
    if(n==1 || m==1)
    count=(n*m);
    else
    count=(2*(n+m))-4;
    return (count+1)/2;
}

void solve()
{
    long long int n,m,x;
    cin>>n>>m>>x;
    map<long long int,long long int>mp;
    long long int start=1;
    while((n>=1) && (m>=1))
    {
        mp[start]=countColors(n,m);
        start++;
        n-=2;
        m-=2;
    }
    cout<<mp[x]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}