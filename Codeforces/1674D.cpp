#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> V(arr.begin(), arr.end());
    sort(V.begin(), V.end());
    int i = 0, j = 1;
    if (n % 2 != 0)
    {
        if (arr[0] != V[0])
        {
            cout << "NO\n";
            return;
        }
        i=1,j=2;
    }
    while(j<=n-1)
    {
        if(!((arr[i]==V[i] && arr[j]==V[j]) || (arr[i]==V[j] && arr[j]==V[i])))
        {
            cout<<"NO\n";
            return;
        }
        i+=2;
        j+=2;
    }
    cout<<"YES\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}