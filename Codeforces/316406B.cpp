#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll is_query = -(1LL<<62);
struct line {
    ll m, b;
    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct dynamic_hull : public multiset<line> { // will maintain upper hull for maximum
    const ll inf = LLONG_MAX;
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

		/* compare two lines by slope, make sure denominator is not 0 */
        ll v1 = (x->b - y->b);
        if (y->m == x->m) v1 = x->b > y->b ? inf : -inf;
        else v1 /= (y->m - x->m);
        ll v2 = (y->b - z->b);
        if (z->m == y->m) v2 = y->b > z->b ? inf : -inf;
        else v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((line) { x, is_query });
        return l.m * x + l.b;
    }
};

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n),minis(n,1e8),pre(n,0),brr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0)
        {
            pre[i]=arr[i];
        }
        else
        {
            pre[i]=pre[i-1]+arr[i];
        }
    }
    for(ll i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    minis[0]=0;
    dynamic_hull Sg1;
    Sg1.insert_line(0, 0);
    vector<ll>ans;
    ans.push_back(0);
    for(ll i=1;i<n;i++)
    {
        ans.push_back((brr[i]*pre[i])-Sg1.eval(brr[i]));
        ll val=ans[ans.size()-1];
        Sg1.insert_line(pre[i-1],-val);
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main()
{
    solve();
    return 0;
}
