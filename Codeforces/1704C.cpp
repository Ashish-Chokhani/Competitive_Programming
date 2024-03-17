#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(m), houses(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < m - 1; i++)
    {
        houses[i] = arr[i + 1] - arr[i] -1;
    }
    houses[m - 1] = (n - arr[m - 1]) + (arr[0] - 1);
    sort(houses.begin(), houses.end());
    int operations = 0, save = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        houses[i]=max(0,houses[i]-(2*operations));
        if ((houses[i] <= 2) && (houses[i] != 0))
        {
            operations += 1;
            save += 1;
        }
        else if (houses[i] > 2)
        {
            operations += 2;
            save += houses[i]-1;   
        }
    }
    cout<<(n-save)<<"\n";
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