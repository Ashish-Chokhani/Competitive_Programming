#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int a, b, q;
    cin >> a >> b >> q;
    long long int lc = (a * b) / gcd(a, b);
    vector<long long int> arr(lc + 1, 0);
    for (long long int i = 1; i <= lc; i++)
    {
        if (((i % a) % b) != ((i % b) % a))
            arr[i] = 1;
    }
    vector<long long int> count(lc + 1, 0);
    for (long long int i = 1; i <= lc; i++)
    {
        count[i] = count[i - 1] + arr[i];
    }
    while(q--)
    {
        long long int l,r;
        cin>>l>>r;
        long long int len1=r;
        long long int n1=len1/lc;
        long long int rem1=len1%lc;
        long long int len2=l-1;
        long long int n2=len2/lc;
        long long int rem2=len2%lc;
        cout<<((n1*count[lc])+count[rem1])-((n2*count[lc])+count[rem2])<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
