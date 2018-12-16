/*input
2 13
ABCDEFGHIJKLM
NOPQRSTUVWXYZ
*/

//
//  main.cpp
//  Fox And Two Dots
//
//  Created by Nirmaljot Singh Bhasin on 21/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <utility>
using namespace std;

typedef long long int lli;
const int MAXN = 51;

string s[MAXN];
bool vis[MAXN][MAXN];
int n, m;

lli row[] = { -1, 0, 0, 1};
lli col[] = {0, -1, 1, 0};

bool dfs(pair<lli, lli> u, pair<lli, lli> p) {
	// cout << "(" << p.first << ", " << p.second << ") -> (" << u.first << ", " << u.second << ") " << s[u.first][u.second] << endl;
	if (!vis[u.first][u.second]) {
		vis[u.first][u.second] = true;
	} else {
		return false;
	}
	bool flag = true;
	for (int i = 0; i < 4; ++i) {
		pair<lli, lli> v = {u.first + row[i], u.second + col[i]};
		if ((v.first >= 0 && v.first < n) &&
		        (v.second >= 0 && v.second < m) &&
		        (v != p) && s[v.first][v.second] == s[u.first][u.second]) {
			flag &= dfs(v, u);
		}
	}
	return flag;
}

int main(int argc, const char * argv[]) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < m; ++j) {
	// 		cout << s[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	bool flag = true;
	for (int i = 0; (i < n); ++i) {
		for (int j = 0; (j < m); ++j) {
			if (!vis[i][j]) {
				flag &= dfs({i, j}, { -1, -1});
				// cout << i << " " << j << " -> " << endl;
				// for (int x = 0; x < n; ++x) {
				// 	for (int y = 0; y < m; ++y) {
				// 		cout << vis[x][y] << " ";
				// 	}
				// 	cout << endl;
				// }
				// cout << endl;
			}
		}
	}
	if (flag) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
	return 0;
}
