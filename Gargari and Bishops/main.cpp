/*input
4
1 1 1 1
2 1 1 0
1 1 1 0
1 0 0 1
*/

//
//  main.cpp
//  Gargari and Bishops
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <utility>
using namespace std;

typedef long long int lli;
const int MAXN = 2003;

lli a[MAXN][MAXN];
lli d1[MAXN << 1], d2[MAXN << 1];
lli ans[2];
pair<lli, lli> v[2];

int main(int argc, const char * argv[]) {
	cin.sync_with_stdio(false);
	
	int n;
	cin >> n;
	ans[0] = ans[1] = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			d1[i + j] += a[i][j];
			d2[i - j + n] += a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (ans[(i + j) & 1] < (d1[i + j] + d2[i - j + n] - a[i][j])) {
				ans[(i + j) & 1] = (d1[i + j] + d2[i - j + n] - a[i][j]);
				v[(i + j) & 1] = {i, j};
			}
		}
	}
	cout << ans[0] + ans[1] << endl;
	cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
	return 0;
}
