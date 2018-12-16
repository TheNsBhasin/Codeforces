/*input
3 4 2
#..#
..#.
#...
*/

//
//  main.cpp
//  Maze
//
//  Created by Nirmaljot Singh Bhasin on 21/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 502;

string s[MAXN];
lli vis[MAXN][MAXN];
lli cnt;
int n, m, k, d;

lli row[] = { -1, 0 , 0, 1};
lli col[] = {0, -1, 1, 0};

bool check(pair<lli, lli> p) {
	if ((p.first >= 0 && p.first < n) && (p.second >= 0 && p.second < m)) {
		return true;
	}
	return false;
}

void dfs(pair<lli, lli> u, pair<lli, lli> p) {
	if (cnt >= d - k) {
		return;
	}
	if (!vis[u.first][u.second]) {
		vis[u.first][u.second] = 1;
		++cnt;
	} else {
		return;
	}
	for (int i = 0; i < 4; ++i) {
		pair<lli, lli> v = {u.first + row[i], u.second + col[i]};
		if (check(v) && v != p && s[v.first][v.second] == '.') {
			dfs(v, u);
		}
	}
}

int main(int argc, const char * argv[]) {
	cin >> n >> m >> k;
	pair<lli, lli> st;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '#') {
				vis[i][j] = -1;
			}
			if (s[i][j] == '.') {
				++d;
				st = {i, j};
			}
		}
	}
	dfs(st, { -1, -1});
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j]) {
				s[i][j] = 'X';
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << s[i] << endl;
	}
	return 0;
}
