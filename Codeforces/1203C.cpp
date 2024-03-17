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
    cin >> n;
    vector<pair<pair<ll,ll>,ll>>arr(n);
    vector<ll>x(n),y(n),a(n);
    for(ll i=0;i<n;i++)
    {
        ll ab,bc,cd;
        cin>>ab>>bc>>cd;
        arr[i].first.first=ab;
        arr[i].first.second=bc;
        arr[i].second=cd;
    }
    sort(arr.begin(),arr.end());
    for(ll i=0;i<n;i++)
    {
        x[i]=arr[i].first.first;
        y[i]=arr[i].first.second;
        a[i]=arr[i].second;
    }
    vector<ll>dp(n,0);
    dp[0]=(x[0]*y[0])-a[0];
    dp[0]=max(0LL,dp[0]);
    ll maxi=dp[0];
    dynamic_hull Sg;
    Sg.insert_line(-x[0],dp[0]);
    for(ll i=1;i<n;i++)
    {
        dp[i]=max(maxi,(x[i]*y[i])-a[i]+Sg.eval(y[i]));
        dp[i]=max(dp[i],(x[i]*y[i])-a[i]);
        Sg.insert_line(-x[i],dp[i]);
        maxi=max(maxi,dp[i]);
    }
    cout<<dp[n-1]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
