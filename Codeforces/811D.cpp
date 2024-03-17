#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char c[4] = {'L', 'R', 'U', 'D'};
pair<ll, ll> pos, cur = {0, 0};
ll dr[4] = {0, 0, -1, 1};
ll dc[4] = {-1, 1, 0, 0};
vector<vector<ll>> vis(101, vector<ll>(101, 0));
string s[101];
ll n, m;

pair<ll, ll> move(char c)
{
    cout << c << "\n";
    ll row, col;
    cin >> row >> col;
    --row;
    --col;
    if (row == pos.first && col == pos.second)
    {
        exit(0);
    }
    return {row, col};
}

void DFS(vector<char> &ch,pair<ll,ll>&pointer)
{
    vis[pointer.first][pointer.second] = 1;

    if (pointer == pos)
    {
        for (ll i = 0; i < ch.size(); i++)
        {
            if (ch[i] == 'L')
                pair<ll, ll> nxt = move(c[0]);
            else if (ch[i] == 'R')
                pair<ll, ll> nxt = move(c[1]);
            else if (ch[i] == 'U')
                pair<ll, ll> nxt = move(c[2]);
            else if (ch[i] == 'D')
                pair<ll, ll> nxt = move(c[3]);
        }
        exit(0);
    }
    for (ll dir = 0; dir < 4; dir++)
    {
        ll nrow = pointer.first + dr[dir];
        ll ncol = pointer.second + dc[dir];
        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && s[nrow][ncol] != '*')
        {
            pair<ll,ll>y={nrow,ncol};
            if(dir==0) ch.push_back('L');
            else if(dir==1) ch.push_back('R');
            else if(dir==2) ch.push_back('U');
            else if(dir==3) ch.push_back('D');
            DFS(ch,y);
            ch.pop_back();
        }
    }
}

void finish()
{
    pair<ll,ll> pointer = cur;
    vector<char> ch;
    DFS(ch,pointer);
}

void solve()
{
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        s[i] = t;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (s[i][j] == 'F')
            {
                pos = {i, j};
                break;
            }
        }
    }
    if (m >= 1 && s[0][1] != '*')
    {
        pair<ll, ll> nxt = move('L');
        if (nxt != cur)
        {
            cur = nxt;
            swap(c[0], c[1]);
        }
        bool is_top = true;
        ll down_pos = -1;
        if (n > 1)
        {
            for (ll i = 0; i < m; i++)
            {
                if (s[1][i] != '*')
                {
                    is_top = false;
                    down_pos = i;
                    break;
                }
            }
        }
        if (is_top)
        {
            finish();
        }
        else
        {
            while (cur.second != down_pos)
            {
                cur = move(c[down_pos > cur.second]);
            }
            nxt = move('U');
            if (nxt != cur)
            {
                cur = nxt;
                swap(c[2], c[3]);
            }
        }
        finish();
    }
    else
    {
        pair<ll, ll> nxt = move('U');
        if (nxt != cur)
        {
            cur = nxt;
            swap(c[2], c[3]);
        }
        bool is_left = true;
        ll right_pos = -1;
        if (m > 1)
        {
            for (ll i = 0; i < n; i++)
            {
                if (s[i][1] != '*')
                {
                    is_left = false;
                    right_pos = i;
                    break;
                }
            }
        }
        if (is_left)
        {
            finish();
        }
        else
        {
            while (cur.first != right_pos)
            {
                cur = move(c[(right_pos > cur.first) + 2]);
            }
            nxt = move('L');
            if (nxt != cur)
            {
                cur = nxt;
                swap(c[0], c[1]);
            }
        }
        finish();
    }
}

int main()
{
    solve();
    return 0;
}