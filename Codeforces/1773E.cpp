#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> arr;
    vector<int> distincts;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        vector<int> V(k);
        for (int j = 0; j < k; j++)
        {
            cin >> V[j];
            distincts.push_back(V[j]);
        }
        arr.push_back(V);
    }
    int split = 0, combine = n - 1;
    int l = distincts.size();
    sort(distincts.begin(), distincts.end());
    for (int i = 0; i < l; i++)
    {
        mp[distincts[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int pointer = mp[arr[i][0]];
        int j = 0;
        while (pointer < l && j < arr[i].size() && (distincts[pointer] == arr[i][j]))
        {
            j++;
            pointer++;
            if (j >= arr[i].size())
                break;
            if (pointer >= l || distincts[pointer] != arr[i][j])
            {
                split++;
                combine++;
                pointer = mp[arr[i][j]];
            }
        }
    }
    cout << split << " " << combine << "\n";
}

int main()
{
    solve();
    return 0;
}
