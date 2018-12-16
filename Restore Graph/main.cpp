/*input
4 2
2 0 1 3
*/

//
//  main.cpp
//  Restore Graph
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

vector<lli> d[MAXN];
vector< pair<lli, lli> > ans;

int main(int argc, const char * argv[]) {
	int n, k;
	cin >> n >> k;
	lli st = -1;
	for (int i = 1; i <= n; ++i) {
		lli x;
		cin >> x;
		d[x].push_back(i);
	}
	bool flag = true;
	if (d[0].size() != 1) {
		flag = false;
	}

	for (int i = 1; (i < MAXN) && flag; ++i) {
		lli edges = (i != 1);
		lli cnt = 0;
		for (int j = 0; j < d[i].size(); ++j) {
			if (edges == k) {
				edges = (i != 1);
				++cnt;
			}
			if (cnt == d[i - 1].size()) {
				flag = false;
				break;
			}
			ans.push_back({d[i - 1][cnt], d[i][j]});
			++edges;
		}
	}
	if (flag) {
		cout << ans.size() << endl;
		for (auto &e : ans) {
			cout << e.first << " " << e.second << endl;
		}
	} else {
		cout << -1 << endl;
	}
	return 0;
}
