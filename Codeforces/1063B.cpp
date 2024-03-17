#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    vector<vector<char>> arr(n, vector<char>(m));
    ll r, c;
    cin >> r >> c;
    --r;
    --c;
    ll x, y;
    cin >> x >> y;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<vector<ll>> dist(n + 1, vector<ll>(m + 1, 1e12));
    dist[r][c] = 0;
    pq.push({0, {r, c}});
    ll dx[4] = {-1, 0, 0, 1};
    ll dy[4] = {0, 1, -1, 0};
    while (!pq.empty())
    {
        ll i = pq.top().second.first;
        ll j = pq.top().second.second;
        ll dis = pq.top().first;
        pq.pop();
        for (ll dir = 0; dir < 4; dir++)
        {
            ll new_x = i + dx[dir];
            ll new_y = j + dy[dir];
            if (new_y >= 0 && new_y < m && new_x >= 0 && new_x < n && arr[new_x][new_y] != '*')
            {
                ll val=new_y<j;
                ll cur_dis = dist[new_x][new_y];
                if (dis + val < cur_dis)
                {
                    dist[new_x][new_y] = dis + val;
                    pq.push({dis + val,{new_x,new_y}});
                }
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll L=dist[i][j];
            ll R=L+j-c;
            if (L<=x && R<=y)
                ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
