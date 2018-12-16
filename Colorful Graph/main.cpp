/*input
6 6
1 1 2 3 5 8
1 2
3 2
1 4
4 3
4 5
4 6
*/

//
//  main.cpp
//  Colorful Graph
//
//  Created by Nirmaljot Singh Bhasin on 12/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

map<lli, lli> hm;
set<lli> vis[MAXN];

int main(int argc, const char *argv[]) {
    hm.clear();
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        lli x;
        cin >> x;
        hm[i] = x;
    }

    for (int i = 0; i < m; ++i) {
        lli u, v;
        cin >> u >> v;
        --u;
        --v;
        if (hm[u] != hm[v]) {
            vis[hm[u]].insert(hm[v]);
            vis[hm[v]].insert(hm[u]);
        }
    }

    lli res = hm[0];
    for (int i = 0; i < n; ++i) {
        if (vis[res].size() < vis[hm[i]].size() ||
            vis[res].size() == vis[hm[i]].size() && res > hm[i]) {
            res = hm[i];
        }
    }

    cout << res << endl;
    return 0;
}
