#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> dp(100005);
ll sz[100005];
vector<ll> ax(100005), by(100005);

const ll is_query = -(1LL << 62);
struct line
{
    ll m, b;
    mutable function<const line *()> succ;
    bool operator<(const line &rhs) const
    {
        if (rhs.b != is_query)
            return m < rhs.m;
        const line *s = succ();
        if (!s)
            return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct dynamic_hull : public multiset<line>
{ // will maintain upper hull for maximum
    const ll inf = LLONG_MAX;
    bool bad(iterator y)
    {
        auto z = next(y);
        if (y == begin())
        {
            if (z == end())
                return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end())
            return y->m == x->m && y->b <= x->b;

        /* compare two lines by slope, make sure denominator is not 0 */
        ll v1 = (x->b - y->b);
        if (y->m == x->m)
            v1 = x->b > y->b ? inf : -inf;
        else
            v1 /= (y->m - x->m);
        ll v2 = (y->b - z->b);
        if (z->m == y->m)
            v2 = y->b > z->b ? inf : -inf;
        else
            v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    void insert_line(ll m, ll b)
    {
        auto y = insert({m, b});
        y->succ = [=]
        { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y))
        {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y)))
            erase(next(y));
        while (y != begin() && bad(prev(y)))
            erase(prev(y));
    }
    ll eval(ll x)
    {
        auto l = *lower_bound((line){x, is_query});
        return l.m * x + l.b;
    }
};

dynamic_hull *cht[100005];

void DFS(ll cur, ll par,vector<ll>*trees)
{
    ll nchild = 0;
    sz[cur] = 1;
    ll bigc = -1, bigs = -1;
    for (auto it : trees[cur])
    {
        if (it != par)
        {
            DFS(it, cur,trees);
            sz[cur] += sz[it];
            if (sz[it] > bigs)
            {
                bigs = sz[it];
                bigc = it;
            }
            nchild++;
        }
    }
    if(nchild==0)
    {
        dp[cur]=0;
        cht[cur]=new dynamic_hull;
        cht[cur]->insert_line(-by[cur],0);
        return;
    }

    cht[cur]=cht[bigc];

    for (auto it : trees[cur])
    {
        if (it != par && it!=bigc)
        {
            for(line l:*cht[it])
            {
                //cht[cur]=new dynamic_hull;
                cht[cur]->insert_line(l.m,l.b);
            }
        }
    }
    dp[cur]=-cht[cur]->eval(ax[cur]);
    cht[cur]->insert_line(-by[cur],-dp[cur]);
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll>trees[100005];
    for (ll i = 0; i < n; i++)
    {
        cin >> ax[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> by[i];
    }
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        trees[u].push_back(v);
        trees[v].push_back(u);
    }
    DFS(0,-1,trees);
    for(ll i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
