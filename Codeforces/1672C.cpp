#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = -2, r = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (arr[i] == arr[i - 1])
        {
            r = i;
            break;
        }
    }
    int x = r - l - 1;
    if(x==0)
    {
    cout << "0\n";    
    }
    else if(x==1)
    {
    cout << "1\n";    
    }
    else
    cout <<(x-1)<< "\n";
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