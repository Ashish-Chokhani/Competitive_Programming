#include <bits/stdc++.h>
using namespace std;

int findLength(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt++;
        n = n / 10;
    }
    return cnt;
}

void DigitalLog(vector<int> &a, vector<int> &b, vector<int> &new_a, vector<int> &new_b)
{
    int i = 0, j = 0;
    int n = a.size();
    while (i < n && j < n)
    {
        if (a[i] > b[j])
        {
            new_b.push_back(b[j]);
            j++;
        }
        else if (b[j] > a[i])
        {
            new_a.push_back(a[i]);
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    while (i < n)
    {
        new_a.push_back(a[i]);
        i++;
    }
    while (j < n)
    {
        new_b.push_back(b[j]);
        j++;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int county = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> new_a, new_b;
    DigitalLog(a, b, new_a, new_b);
    for (int i = 0; i < new_a.size(); i++)
    {
        int len = findLength(new_a[i]);
        if (len > 1)
        {
            county++;
            new_a[i] = len;
        }
    }
    for (int i = 0; i < new_b.size(); i++)
    {
        int len = findLength(new_b[i]);
        if (len > 1)
        {
            county++;
            new_b[i] = len;
        }
    }
    sort(new_a.begin(), new_a.end());
    sort(new_b.begin(), new_b.end());
    vector<int> new_a1, new_b1;
    DigitalLog(new_a, new_b, new_a1, new_b1);
    for (int i = 0; i < new_a1.size(); i++)
    {
        if (new_a1[i] > 1)
            county++;
        if (new_b1[i] > 1)
            county++;
    }
    cout << county << "\n";
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