#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(int len, string A, map<char, int> &mp, pair<int, int> &ans, int a)
{
    map<char, int> temp;
    for (int i = 0; i < min(a, len); i++)
    {
        temp[A[i]]++;
    }
    set<char> st;
    for (auto it : mp)
    {
        if (temp[it.first] < it.second)
        {
            st.insert(it.first);
        }
    }
    if (st.size() == 0)
    {
        ans.first = 0;
        ans.second = len - 1;
        return true;
    }
    int l = 1, r = len;
    while (r < a)
    {
        temp[A[l-1]]--;
        temp[A[r]]++;
        if ((temp[A[l-1]] < mp[A[l-1]]) && mp[A[l-1]]>0)
        {
            st.insert(A[l-1]);
        }
        if ((temp[A[r]] >= mp[A[r]]) && mp[A[r]]>0)
        {
            auto it = st.find(A[r]);
            st.erase(it);
        }
        if (st.size() == 0)
        {
            ans.first = l;
            ans.second = r;
            return true;
        }
        l++;
        r++;
    }
    return false;
}

void solve()
{
    string A="ADOBECODEBANC";
    string B="ABC";
    map<char, int> mp;
    int a = A.length();
    int b = B.length();
    for (int i = 0; i < b; i++)
    {
        mp[B[i]]++;
    }
    int l = b, r = a;
    pair<int, int> ans;
    ans.first = -1, ans.second = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (isPossible(mid, A, mp, ans, a))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    string s = "";
    if (ans.first != -1)
        s = A.substr(ans.first, ans.second - ans.first + 1);
    cout<<s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}