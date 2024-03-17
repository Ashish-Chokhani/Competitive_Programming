#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> ans;
    if (s[0] - '0' >= 5 && s[0] - '0' <= 8)
    {
        ans.push_back(9 - (s[0] - '0'));
    }
    else
        ans.push_back(s[0] - '0');
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] - '0' >= 5 && s[i] - '0' <= 9)
        {
            ans.push_back(9 - (s[i] - '0'));
        }
        else
            ans.push_back(s[i] - '0');
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    cout << "\n";
    if (ans.size() == 0)
        cout << "9\n";
    return 0;
}