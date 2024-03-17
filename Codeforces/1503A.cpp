#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push('(');
        else
        {
            if (st.empty())
                return false;
            st.pop();
        }
    }
    return st.size() == 0;
}

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st1, st2;
    string s1 = "", s2 = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (st1.empty() || st2.empty())
            {
                st1.push('(');
                st2.push('(');
                s1 += '(';
                s2 += '(';
            }
            else
            {
                if (i==n-1 || (st1.size()>1 || st2.size()>1) || (i + 1 < n && s[i + 1] != '0'))
                {
                    st1.pop();
                    st2.pop();
                    s1 += ')';
                    s2 += ')';
                }
                else
                {
                    st1.push('(');
                    st2.push('(');
                    s1 += '(';
                    s2 += '(';
                }
            }
        }
        else
        {
            int n1 = st1.size(), n2 = st2.size();

            if (n1 == 0 && n2 == 0)
            {
                cout << "NO\n";
                return;
            }
            else if (n1 <= n2)
            {
                st1.push('(');
                st2.pop();
                s1 += '(';
                s2 += ')';
            }
            else
            {
                st2.push('(');
                st1.pop();
                s2 += '(';
                s1 += ')';
            }
        }
        //cout<<s1<<" "<<s2<<"\n";
    }
    if (isValid(s1) && isValid(s2))
    {
        cout << "YES\n";
        cout << s1 << "\n"
             << s2 << "\n";
    }
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    ll cnt = 0;
    while (t--)
    {
            solve();
    }
    return 0;
}