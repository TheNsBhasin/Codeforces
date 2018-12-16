/*input
6
0 1 1 0 4 4
7
1 1
1 2
2 1
2 2
4 1
5 1
6 1
*/

//
//  main.cpp
//  Blood Cousins
//
//  Created by Nirmaljot Singh Bhasin on 19/08/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;

typedef long long int lli;

const int MAXN = 100005;
const int LN = 17;

int parent[MAXN][LN], L[MAXN], R[MAXN], arr[MAXN], depth[MAXN], cnt;
vector<int> child[MAXN], tree[MAXN * 4];

void dfs(int u) {
    L[u] = ++cnt;
    arr[cnt] = depth[u];
    for (int v : child[u]) {
        depth[v] = depth[u] + 1;
        dfs(v);
    }
    R[u] = cnt;
}

void build(int l, int r, int idx) {
    for (int i = l; i <= r; i++) {
        tree[idx].push_back(arr[i]);
    }
    sort(tree[idx].begin(), tree[idx].end());
    if (l == r) {
        return;
    }
    int mid = l + (r - l) / 2;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
}

lli query(int idx, int l, int r, int ll, int rr, int x) {
    if (ll > r || rr < l) {
        return 0;
    }
    if (ll <= l && r <= rr) {
        return upper_bound(tree[idx].begin(), tree[idx].end(), x) - lower_bound(tree[idx].begin(), tree[idx].end(), x);
    }
    int mid = l + (r - l) / 2;
    return query(idx * 2, l, mid, ll, rr, x) + query(idx * 2 + 1, mid + 1, r, ll, rr, x);
}

int getParent(int v, int diff) {
    while (diff > 0) {
        int log = log2(diff);
        v = parent[v][log];
        diff -= (1 << log);
    }
    return v;
}

lli solve(int v, int p) {
    int par = getParent(v, p);
    if (par == 0) {
        return 0;
    }
    return query(1, 1, cnt, L[par], R[par], depth[v]) - 1;
}

int main(int argc, const char * argv[]) {
    int n, m;
    int v, p;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> parent[i][0];
        child[parent[i][0]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < LN; ++j) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
    cnt = 0;
    dfs(0);
    build(1, cnt, 1);
    cout << endl;
    cin >> m;
    while (m--) {
        cin >> v >> p;
        cout << solve(v, p) << " ";
    }
    return 0;
}
