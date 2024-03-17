#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define el '\n';
 
#define fr1(i,a,n) for(ll i=a; i<n; ++i)
 
#define fast \
ios_base::sync_with_stdio(0); \
cin.tie(0);	  	      \
cout.tie(0);		      \
 
class DisjointSet {
public:
    vector<ll> rank, parent, siz;
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        siz.resize(n+1, 1);
        parent.resize(n+1);
        fr1(i, 0, n+1) parent[i]=i;
    }
 
    int findupar(int node) {
        if(node==parent[node]) return node;
        return parent[node]=findupar(parent[node]);
    }
 
    void unionbyrank(int u, int v) {
        int ulpu = findupar(u);
        int ulpv = findupar(v);
        if(ulpu == ulpv) return;
        if(rank[ulpu] < rank[ulpv]) parent[ulpu] = ulpv;
        else if(rank[ulpv] < rank[ulpu]) parent[ulpv] = ulpu;
        else {
            parent[ulpv] = ulpu;
            rank[ulpu]++;
        }
    }
 
    void unionbysize(int u, int v) {
        int ulpu = findupar(u);
        int ulpv = findupar(v);
        if(ulpu == ulpv) return;
        if(siz[ulpu] < siz[ulpv]) {
            parent[ulpu] = ulpv;
            siz[ulpv] += siz[ulpu];
        }
        else {
            parent[ulpv] = ulpu;
            siz[ulpu] += siz[ulpv];
        }
    }
};
 
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
 
int main(){
    fast
    ll n; cin>>n;
    ll r1, c1, r2, c2;
    cin>>r1>>c1>>r2>>c2;
    r1--;
    c1--;
    r2--;
    c2--;
    vector<string> a(n);
    for(ll i=0; i<n; i++) {
        cin>>a[i];
    }
    DisjointSet ds(n*n);
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            if(a[i][j] == '1') continue;
            for(int k=0; k<4; k++) {
                int nr = i+dr[k];
                int nc = j+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n && a[nr][nc]=='0') {
                    ll pc = (i*n)+j;
                    ll qc = (nr*n)+nc;
                    ds.unionbysize(pc, qc);
                }
            }
        }
    }
    ll cost = 1e9;
    ll dsc1 = (r1*n)+c1, dsc2 = (r2*n)+c2;
    if(ds.findupar(dsc1) == ds.findupar(dsc2)) {
        cout<<0<<el;
        return 0;
    }
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            if(a[i][j]=='1') continue;
            ll ds_node1 = (i*n)+j;
            if(ds.findupar(ds_node1) == ds.findupar(dsc1)) {
                for(ll k=0; k<n; k++) {
                    for(ll l=0; l<n; l++) {
                        if(a[k][l]=='1') continue;
                        ll ds_node2 = (k*n)+l;
                        if(ds.findupar(ds_node2) == ds.findupar(dsc2)) {
                            ll tcost = ((i-k)*(i-k)) + ((j-l)*(j-l));
                            cost = min(cost, tcost);
                        }
                    }
                }
            }
        }
    }
    cout<<cost<<el;
    return 0;
}