#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, m;
    cin >> n >> m;
    set<long long int> row,col;
    long long int a=n*n;
    for (long long int i = 1; i <= m; i++)
    {
        long long int x,y;
        cin>>x>>y;
        row.insert(x);
        col.insert(y);
        long long int l1=row.size();
        long long int l2=col.size();
        cout<<a-((n*(l1+l2))-(l1*l2))<<" ";
    }
}

int main()
{
    solve();
    return 0;
}
