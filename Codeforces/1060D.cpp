#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> l(n),r(n);
    for (long long int i = 0; i < n; i++)
    {
        long long int a, b;
        cin >> a >> b;
        l[i]=a;
        r[i]=b;
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    long long int cost=0;
    for(long long int i=0;i<n;i++)
    {
        cost+=max(l[i],r[i]);
    }
    cout<<cost+n<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
