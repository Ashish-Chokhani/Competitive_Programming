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
    int i = 0, j = n - 1, leftwt = 0, rightwt = 0, ans = 0, previ = -1, prevj = -1;
    while (i < j)
    {
        if (previ != i)
            leftwt += arr[i];
        if (prevj != j)
            rightwt += arr[j];
        previ = i;
        prevj = j;
        if (leftwt < rightwt)
            i++;
        else if (rightwt < leftwt)
            j--;
        else
        {
            ans = max(ans, i + 1 + n - j);
            leftwt = 0;
            rightwt = 0;
            i++;
            j--;
        }
    }
    cout<<ans<<"\n";
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