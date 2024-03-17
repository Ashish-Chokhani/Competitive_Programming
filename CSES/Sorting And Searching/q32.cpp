#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_MACHINE
#include "debug.h"
#else
#define debug(...) 42
#endif


/* Policy Based Data Structures */

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/*
indexed_set that is like a set but can be indexed like an array.
It supports the same operations as set, along with 2 new features.

find_by_order(k) = returns an iterator to the k-th largest element (0-based
Indexing).
order_of_key(item) returns the number of items in a set that are
STRICTLY SMALLER than our item.
*/
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

/*
To use it like a multiset, define as below..
insert element as {element, time}
*/

using indexed_map = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;



void solve(int testcase = 1) {
    cout << "ok";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcases = 1;
    // cin >> testcases;
    for (int testcase = 1; testcase <= testcases; ++testcase) {
        solve(testcase);
    }
}