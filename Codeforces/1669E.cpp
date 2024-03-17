#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    vector<string> arr(n);
    vector<long long int> freq(121, 0);
    for (long long int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr[i] = s;
        long long int no = (s[0] - 97) * 11 + (s[1] - 97);
        freq[no]++;
    }

    long long int ans = 0;

    for (long long int i = 0; i < n; i++)
    {
        string s = arr[i];
        long long int no = (s[0] - 97) * 11 + (s[1] - 97);
        freq[no]--;
        long long int type1 = 11 * (s[0] - 97);
        long long int type2 = s[1] - 97;
        for (long long int j = type1; j <= type1 + 10; j++)
        {
            if (j != no)
                ans += freq[j];
        }
        for (long long int j = 0; j <= 110; j+=11)
        {
            long long int x=j+type2;
            if (x != no)
                ans += freq[x];
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}