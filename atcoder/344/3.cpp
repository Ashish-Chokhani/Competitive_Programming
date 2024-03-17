#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
//              tree_order_statistics_node_update>ordered_set;
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for set use less instead of less_equals
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

void solve() {
    ll n, m, l, q;
    cin >> n;
    vector<ll> arr(n);
    for(auto &x : arr) {
        cin >> x;
    }
    cin >> m;
    vector<ll> brr(m);
    for(auto &x : brr) {
        cin >> x;
    }
    cin >> l;
    vector<ll> crr(l);
    for(auto &x : crr) {
        cin >> x;
    }
    cin >> q;
    vector<ll> X(q);
    for(auto &x : X) {
        cin >> x;
    }
    sort(crr.begin(), crr.end());
    unordered_set<ll> isPossible;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            isPossible.insert(arr[i] + brr[j]);
        }
    }
    for(ll i = 0; i < q; i++) {
        string ans = "No";
        for(ll j = 0; j < l && crr[j] <= X[i]; j++) {
            if(isPossible.count(X[i] - crr[j])) {
                ans = "Yes";
                break;
            }
        }
        cout << ans << endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("error.txt","w",stderr);
    //#endif
    
    ll t;
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}