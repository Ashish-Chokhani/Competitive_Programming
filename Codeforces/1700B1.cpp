#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    vector<char> s(n), ans1(n,0);
    vector<int> ans(n);
    string s3;
    cin >> s3;
    for (int i = 0; i < n; i++)
    {
        s[i] = s3[i];
    }
    if (s[0] != '9')
    {
        for (int i = 0; i < n; i++)
        {
            ans[i]+= 9 - (s[i] - '0');
        }
    }
    else
    {
        for (int i = n-1; i >=0; i--)
        {
            ans[i]+= 9 - (s[i] - '0')+1;
            int r=ans[i]%10;
            if(ans[i]>=10)
            {
            ans[i-1]+=ans[i]/10;
            ans[i]=r;
            }
        }
        ans[n - 1] += 1;
        if(ans[n-1]>=10)
        {
            int i=n-1;
            while(ans[i]>=9)
            {
            int r=ans[i]%10;
            ans[i-1]+=ans[i]/10;;
            ans[i]=r;
            i--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans1[i] = ans[i]+'0';
    }
    string y(ans1.begin(), ans1.end());
    cout << y << "\n";
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
