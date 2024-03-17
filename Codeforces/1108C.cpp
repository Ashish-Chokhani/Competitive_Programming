#include <bits/stdc++.h>
using namespace std;

string Generate(int n, char first, char second, char third)
{
    string s = "";
    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0)
            s += first;
        else if (i % 3 == 1)
            s += second;
        else
            s += third;
    }
    return s;
}

int Compare(int n, string &s1, string &s2)
{
    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
            diff++;
    }
    return diff;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string>st;
    string s1 = Generate(n, 'R', 'G', 'B');
    st.push_back(s1);
    string s2 = Generate(n, 'R', 'B', 'G');
    st.push_back(s2);
    string s3 = Generate(n, 'B', 'G', 'R');
    st.push_back(s3);
    string s4 = Generate(n, 'B', 'R', 'G');
    st.push_back(s4);
    string s5 = Generate(n, 'G', 'R', 'B');
    st.push_back(s5);
    string s6 = Generate(n, 'G', 'B', 'R');
    st.push_back(s6);

    int mini=n+2,mini_type=-1;
    for(int type=0;type<6;type++)
    {
        int x=Compare(n,st[type],s);
        if(x<mini)
        {
            mini=x;
            mini_type=type;
        }
    }
    cout<<mini<<"\n";
    cout<<st[mini_type]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
