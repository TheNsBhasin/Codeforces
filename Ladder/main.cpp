/*input
8 6
1 2 1 3 3 5 2 1
1 3
2 3
2 4
8 8
1 4
5 8
*/

//
//  main.cpp
//  Ladder
//
//  Created by Nirmaljot Singh Bhasin on 21/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli a[MAXN], rt[MAXN], lt[MAXN];

int main(int argc, const char * argv[]) {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		if (a[i + 1] >= a[i]) {
			rt[i + 1] = rt[i] + 1;
		}
		if (a[i + 1] <= a[i]) {
			lt[i + 1] = lt[i] + 1;
		}
	}
	for (int i = 1; i <= m; ++i) {
		lli l, r;
		cin >> l >> r;
		if (r - lt[r] - rt[r - lt[r]] <= l || r - lt[r] <= l) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
