/*input
6
6 4 2 7 2 7
3
2 3 6
1 3 4
1 1 6
*/

//
//  main.cpp
//  Kuriyama Mirai's Stones
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli v[MAXN], pre1[MAXN], pre2[MAXN];

int main(int argc, const char * argv[]) {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		pre1[i] = pre1[i - 1] + v[i];
	}
	sort(v + 1, v + n + 1);
	for (int i = 1; i <= n; ++i) {
		pre2[i] = pre2[i - 1] + v[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		lli ty, l, r;
		cin >> ty >> l >> r;
		if (ty == 1) {
			cout << pre1[r] - pre1[l - 1] << endl;
		} else {
			cout << pre2[r] - pre2[l - 1] << endl;
		}
	}
	return 0;
}
