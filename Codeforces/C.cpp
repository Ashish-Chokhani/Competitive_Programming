
// C++ Program to  Declare
// Comparator For Set Of Pair
#include <bits/stdc++.h>
 
using namespace std;
 
// Declaring a custom comparator
struct comp {
    // Operator() overloading
    bool operator()(const pair<int, int>& p1,
                    const pair<int, int>& p2)
    {
        // new definition
        return p1.second - p2.second;
    }
};

int main()
{
    // Declaring a set of pairs with comparator
    set<pair<int, int>, comp> s;
 
    // Adding pairs into the set
    s.insert({ 4, 3 });
    s.insert({ 5, 2 });
    s.insert({ 6, 1 });
    s.insert({ 7, 0 });
 
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << i->first << " " << i->second << endl;
    }
 
    return 0;
}