/*input
3 1
B
B
W
*/

//
//  main.cpp
//  Convex Shape
//
//  Created by Nirmaljot Singh Bhasin on 21/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 51;

string s[MAXN];
vector< pair<lli, lli> > v;

int main(int argc, const char * argv[]) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'B') {
				v.push_back({i, j});
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			lli x1 = v[i].first;
			lli y1 = v[i].second;
			lli x2 = v[j].first;
			lli y2 = v[j].second;
			if (x1 == x2) {
				for (int k = y1; k <= y2; ++k) {
					if (s[x1][k] != 'B') {
						flag = false;
					}
				}
			} else if (y1 == y2) {
				for (int k = x1; k <= x2; ++k) {
					if (s[k][y1] != 'B') {
						flag = false;
					}
				}
			} else {
				if (s[x1][y2] != 'B' && s[x2][y1] != 'B') {
					flag = false;
				}
			}
		}
	}
	if (flag) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
