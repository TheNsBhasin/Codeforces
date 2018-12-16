/*input
1 1 3
10
*/

//
//  main.cpp
//  Anya and Ghosts
//
//  Created by Nirmaljot Singh Bhasin on 23/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 3001;

lli a[MAXN], mark[MAXN];

int main(int argc, const char * argv[]) {
	int m, t, r;
	cin >> m >> t >> r;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	if (t < r) {
		cout << -1 << endl;
		return 0;
	}
	lli ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = a[i] - 1; mark[a[i]] < r; --j) {
			for (int k = j + 1; k <= j + t; ++k) {
				if (k >= 0) {
					++mark[k];
				}
			}
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
