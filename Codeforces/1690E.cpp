#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n);
    vector<long long int> ans(n);
    long long int s=0;
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s+=arr[i]/k;
        ans[i]=arr[i]%k;
    }
    sort(ans.begin(), ans.end());
    long long int i=0,j=n-1;
    while(i<j)
    {
        if(ans[i]+ans[j]>=k)
        {
        s+=(ans[i] + ans[j])/k;
        i++;
        j--;
        }
        else
        i++;
    }
    cout << s << "\n";
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}