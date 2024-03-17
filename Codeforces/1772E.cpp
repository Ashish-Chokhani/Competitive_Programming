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
    vector<int> first, second;
    map<int, int> f1, s1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            first.push_back(i + 1);
            f1[i + 1] = 1;
        }
        if (arr[i] != n - i)
        {
            second.push_back(n - i);
            s1[n - i] = 1;
        }
    }
    int n1 = first.size(), n2 = second.size();
    vector<int> f, s;
    for (int i = 0; i < n1; i++)
    {
        if (!s1[first[i]])
            f.push_back(first[i]);
    }
    for (int i = 0; i < n1; i++)
    {
        if (s1[first[i]])
            f.push_back(first[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        if (!f1[second[i]])
            s.push_back(second[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        if (f1[second[i]])
            s.push_back(second[i]);
    }
    int i = 0, j = 0;
    int left1 = n1, left2 = n2;
    map<int, int> mp1, mp2;
    int turn = 0;
    while (i < n1 && j < n2 && left1 > 1 && left2 > 1)
    {
        if (!mp1[f[i]])
            left1--;
        mp1[f[i]] = 1;
        if (s1[f[i]])
        {
            left2--;
            mp2[f[i]] = 1;
        }
        turn = 1;
        if (left2 <= 1)
            break;
        i++;
        if (!mp2[s[j]])
            left2--;
        mp2[s[j]] = 1;
        if (f1[s[j]])
        {
            left1--;
            mp1[s[j]] = 1;
        }
        j++;
        turn = 0;
    }
    //cout << left1 << " " << left2 << "\n";
    if (left1 == 1 && left2 == 1)
    {
        int l1 = -1, l2 = -1;
        for (int i = 0; i < n1; i++)
        {
            if (!mp1[f[i]])
            {
                l1 = f[i];
                break;
            }
        }
        for (int i = 0; i < n2; i++)
        {
            if (!mp2[s[i]])
            {
                l2 = s[i];
                break;
            }
        }
        if (l1 == l2)
        {
            cout << "Tie\n";
        }
        else
        {
            if (turn == 0)
            {
                cout << "First\n";
            }
            else
            {
                cout << "Second\n";
            }
        }
    }
    else if (left1 == 1 && left2 > 1)
    {
        if (left2 >= 3 || turn == 0)
            cout << "First\n";
        else
        {
            for (int i = 0; i < n1; i++)
            {
                if (!mp1[f[i]] && !mp2[f[i]])
                {
                    cout << "Tie\n";
                    return;
                }
            }
            cout << "First\n";
        }
    }
    else if (left2 == 1 && left1 > 1)
    {
        if (left1 >= 3 || turn == 1)
            cout << "Second\n";
        else
        {
            for (int i = 0; i < n1; i++)
            {
                if (!mp1[f[i]] && !mp2[f[i]])
                {
                    cout << "Tie\n";
                    return;
                }
            }
            cout << "Second\n";
        }
    }
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
