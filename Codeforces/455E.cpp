#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> p(100004,0),a(100004,0);

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
    __int128 eval(ll x) {
        auto l = *lower_bound((line) { x, is_query });
        return ((__int128) l.m) * x + l.b;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,s;
    cin>>n>>s;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        swap(arr[i].first,arr[i].second);
    }
    sort(arr.begin(),arr.end());
    vector<pair<ll,ll>>dp(n);
    dynamic_hull cht;
    dp[0]={0,0};
    cht.insert_line(arr[0].second,dp[0].second - dp[0].first*arr[0].second);
    for(ll i=1;i<n;i++)
    {
        ll l=dp[i-1].first;
        ll r=s+50;
        while(l<=r)
        {
            ll mid=(l+r)/2;

            __int128 c=cht.eval(mid);

            if(c>=arr[i].first)
            r=mid-1;
            else
            l=mid+1;
        }
        ll c=cht.eval(l);
        dp[i]={l,c-arr[i].first};
        cht.insert_line(arr[i].second,dp[i].second-dp[i].first*arr[i].second);
    }
    ll ans=1e17;
    for(ll i=0;i<n;i++)
    {
        ll val=(s-dp[i].second + arr[i].second -1)/arr[i].second;
        ans=min(ans,dp[i].first+val);
    }
    cout<<ans<<"\n";
}
