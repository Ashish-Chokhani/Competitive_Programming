#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string s1="",s2="";
    vector<int>s_a,t_a,s_c,t_c;
    for(int i=0;i<n;i++)
    {
        if(s[i]!='b') s1+=s[i];
        if(t[i]!='b') s2+=t[i];
    }
    if(s1!=s2)
    {
        cout<<"NO\n";
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a') 
        s_a.push_back(i);
        else if(s[i]=='c')
        s_c.push_back(i);

        if(t[i]=='a') 
        t_a.push_back(i);
        else if(t[i]=='c')
        t_c.push_back(i);   
    }
    for(int i=0;i<s_a.size();i++)
    {
        if(s_a[i]>t_a[i])
        {
            cout<<"NO\n";
            return;
        }
    }
    for(int i=0;i<s_c.size();i++)
    {
        if(s_c[i]<t_c[i])
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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