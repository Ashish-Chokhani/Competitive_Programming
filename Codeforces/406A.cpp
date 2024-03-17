#include <bits/stdc++.h>
using namespace std;

void printV(vector<int> & V)
{
    for(auto it:V)
    cout<<it<<" ";
    cout<<"\n";
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>matrix(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++)
        cin >> matrix[i][j];
    }
    vector<int>rows(n,0),col(n,0);
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++)
        rows[i]=rows[i]^matrix[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++)
        col[i]=col[i]^matrix[j][i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i;
            cin >>i;
            i--;
            rows[i]=1-rows[i];
            cout<<"type 1<<\n";
            printV(rows);
            printV(col);
        }
        else if (type == 2)
        {
            int j;
            cin >> j;
            j--;
            col[j]=1-col[j];
            cout<<"type 2<<\n";
            printV(rows);
            printV(col);
        }
        else
        {
            int x=0;
           for (int i = 0; i < n; i++)
           { 
            x=x^(rows[i] & col[i]);
           }
           cout<<x<<"\n";
        }
    }
    cout<<"\n";
}

int main()
{
    solve();
    return 0;
}