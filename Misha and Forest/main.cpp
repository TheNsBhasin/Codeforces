/*input
2
1 1
1 0
*/

//
//  main.cpp
//  Misha and Forest
//
//  Created by Nirmaljot Singh Bhasin on 23/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int MOD = 1000000007;

lli deg[MAXN], xorsum[MAXN];
queue<lli> q;
vector< pair<lli, lli> > ans;
lli cnt;

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> deg[i] >> xorsum[i];
		if (deg[i] == 1) {
			q.push(i);
		}
		if (deg[i] == 0) {
			++cnt;
		}
	}
	while (!q.empty()) {
		lli u = q.front();
		q.pop();
		if (deg[u] == 0) {
			continue;
		}
		lli v = xorsum[u];
		deg[u] = xorsum[u] = 0;
		ans.push_back({u, v});
		++cnt;
		--deg[v];
		xorsum[v] ^= u;
		if (deg[v] == 1) {
			q.push(v);
		}
	}
	cout << ans.size() << endl;
	for (auto &p : ans) {
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}
