/*input
2
2 1
1 2
*/

//
//  main.cpp
//  Ice Skating
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef long long int lli;

vector< pair<pair<lli, lli>, bool> > v;

void dfs(lli i, lli n) {
	if (v[i].second) {
		return;
	}
	v[i].second = true;
	for (int j = 0; j < n; ++j) {
		if ((v[j].first).first == (v[i].first).first || (v[j].first).second == (v[i].first).second) {
			dfs(j, n);
		}
	}
}

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		lli x, y;
		cin >> x >> y;
		v.push_back({{x, y}, false});
	}
	lli cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i].second) {
			continue;
		}
		++cnt;
		dfs(i, n);
	}
	cout << cnt - 1 << endl;
	return 0;
}
