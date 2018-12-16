/*input
5
1 2
1 3
2 4
2 5
2
1 4
3 5
*/

//
//  main.cpp
//  Fools and Roads
//
//  Created by Nirmaljot Singh Bhasin on 20/08/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long int lli;

const int MAXN = 100005;
const int LN = 20;

vector<int> adj[MAXN];
vector<pair<int, int> > edges;
int parent[MAXN][LN], depth[MAXN], cnt[MAXN];

void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    parent[u][0] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }
}

int LCA(int u, int v)
{
    if (depth[v] < depth[u]) {
        swap(u, v);
    }
    int diff = depth[v] - depth[u];
    while (diff > 0) {
        int log = (log2(diff));
        v = parent[v][log];
        diff -= (1 << log);
    }
    while (u != v) {
        int i = (log2(depth[u]));
        for (; i > 0 && parent[u][i] == parent[v][i];)
            i--;
        u = parent[u][i];
        v = parent[v][i];
    }
    return u;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k;
    int u, v;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back(make_pair(u, v));
    }
    dfs(1, 0);

    for (int i = 1; i < LN; i++) {
        for (int u = 1; u <= n; u++) {
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
        }
    }

    cin >> k;
    while (k--) {
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
        cnt[LCA(u, v)] -= 2;
    }
    dfs(1, 0);
    for (int i = 0; i <= n; ++i) {
        cout << cnt[i] << " ";
    }
    cout << endl;
    for (auto e : edges) {
        u = e.first; v = e.second;
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        cout << cnt[u] << " ";
    }
    cout << endl;
    return 0;
}