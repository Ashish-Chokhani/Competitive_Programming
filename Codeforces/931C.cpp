#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        st.insert(arr[i]);
    }
    sort(arr.begin(), arr.end());
    if (st.size() <= 1)
    {
        cout << n << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        int same = n;
        int i = 0, j = n - 1;
        vector<int> arr1(arr.begin(), arr.end());
        while ((i < j) && (arr1[j] - arr1[i] == 2))
        {
            arr1[j]--;
            arr1[i]++;
            i++;
            j--;
            same -= 2;
        }
        int same1 = n;
        if (st.size() == 3)
        {
            vector<int> V(st.begin(), st.end());
            for (int k = 0; k < n; k++)
            {
                if (arr[k] == V[1])
                {
                    i = k;
                    break;
                }
            }
            for (int k = 0; k < n; k++)
            {
                if (arr[k] == V[1])
                {
                    j = k;
                }
            }
            while (i < j)
            {
                arr[j]++;
                arr[i]--;
                i++;
                j--;
                same1 -= 2;
            }
        }
        if (same <= same1)
        {
            cout << same << "\n";
            for (int k = 0; k < n; k++)
            {
                cout << arr1[k] << " ";
            }
        }
        else
        {
            cout << same1 << "\n";
            for (int k = 0; k < n; k++)
            {
                cout << arr[k] << " ";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}