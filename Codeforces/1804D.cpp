#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to generate all binary strings
void generateAllBinaryStrings(vector<ll> &ar, ll i, vector<vector<ll>> &arr)
{
    if (i == 8)
    {
        arr.push_back(ar);
        return;
    }

    // First assign "0" at ith position
    // and try for all other permutations
    // for remaining positions
    ar.push_back(0);
    generateAllBinaryStrings(ar, i + 1, arr);
    ar.pop_back();

    // And then assign "1" at ith position
    // and try for all other permutations
    // for remaining positions
    ar.push_back(1);
    generateAllBinaryStrings(ar, i + 1, arr);
    ar.pop_back();
}

ll countOnes(vector<ll> &arr, ll m)
{
    ll cnt = 0;
    for (ll i = 0; i < m; i++)
    {
        cnt += arr[i] == 1;
    }
    return cnt;
}

ll countConsecutive(vector<ll> &arr, ll m)
{
    ll j = 0;
    ll tot = 0;
    while (j < m)
    {
        if (arr[j] == 1)
        {
            ll len = 0;
            while (j < m && arr[j] == 1)
            {
                len++;
                j++;
            }
            tot += len / 2;
        }
        j++;
    }
    return tot;
}

ll countConsecutives(vector<ll> &arr, ll m)
{
    ll j = 0;
    ll tot = 0;
    while (j < m)
    {
        ll flag=0;
        if (arr[j] == 1)
        {
            ll len = 0;
            if(j>=1 && arr[j-1]==0)
            len--;
            while (j < m && arr[j] == 1)
            {
                len++;
                j++;
            }
            if(j<m)
            len--;
            tot += len;
        }
        j++;
    }
    return tot;
}

void solve()
{
    // ll n,m;
    // cin>>n>>m;
    vector<vector<ll>> arr;
    vector<ll> ar;
    // for(ll i=0;i<n;i++)
    // {
    //     string s;
    //     cin>>s;
    //     for(ll j=0;j<m;j++)
    //     {
    //         arr[i][j]=s[j]-'0';
    //     }
    // }
    generateAllBinaryStrings(ar, 0, arr);
    ll mini = 0, maxi = 0;
    ll n = 256, m = 8;
    for (ll i = 0; i < n; i++)
    {
        ll cnt_ones = countOnes(arr[i], m);
        ll cons = countConsecutive(arr[i], m);
        ll cons2 = countConsecutives(arr[i], m);
        ll mini_val = min(m / 4, cons);
        mini += cnt_ones - mini_val;
        ll maxi_val = min(m / 2, cons2);
        ll rem_val = cons2 - maxi_val;
        ll pairs=(rem_val+1)/2;
        maxi += cnt_ones - pairs;
        if(i==207)
        {
            cout<<maxi_val<<" "<<rem_val<<" "<<pairs<<" "<<cons2<<"\n";
            for (ll j = 0; j < m; j++)
            {
                cout << arr[i][j];
            }
            cout << "---" << cnt_ones - mini_val << " " << cnt_ones - pairs << "\n";
        }
    }
    cout << mini << " " << maxi << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
