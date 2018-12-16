/*input
2
7 91
2
1 2
2 1
*/

//
//  main.cpp
//  Checkposts
//
//  Created by Nirmaljot Singh Bhasin on 22/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <memory.h>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int MOD = 1000000007;

lli a[MAXN], mini[MAXN], cnt[MAXN];
lli low[MAXN], dtime[MAXN], st[MAXN], comp[MAXN];
vector<lli> adj[MAXN];
bool in[MAXN];
lli comps, dfs_time, siz;

void tarjan(lli u) {
	low[u] = dtime[u] = ++dfs_time;
	st[siz++] = u;
	in[u] = true;

	for (auto &v : adj[u]) {
		if (dtime[v] == -1) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (in[v]) {
			low[u] = min(low[u], dtime[v]);
		}
	}

	if (dtime[u] == low[u]) {
		++comps;
		lli v = -1;
		do {
			v = st[--siz];
			in[v] = false;
			comp[v] = comps;
		} while (u != v);
	}
}

int main(int argc, const char * argv[]) {
	memset(dtime, -1, sizeof(dtime));
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		lli u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	comps = dfs_time = siz = 0;
	for (int i = 1; i <= n; ++i) {
		if (dtime[i] == -1) {
			tarjan(i);
		}
	}

	for (int i = 1; i <= comps; ++i) {
		mini[i] = LONG_MAX;
	}

	for (int i = 1; i <= n; ++i) {
		lli c = comp[i];
		if (mini[c] > a[i]) {
			mini[c] = a[i];
			cnt[c] = 1;
		} else if (mini[c] == a[i]) {
			++cnt[c];
		}
	}

	lli cost = 0, ways = 1;
	for (int i = 1; i <= comps; ++i) {
		cost += mini[i];
		ways = (ways * cnt[i]) % MOD;
	}
	cout << cost << " " << ways << endl;
	return 0;
}
