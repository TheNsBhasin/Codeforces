/*input
5
1 2 3 6 6
4
1 1
3 1
1 1
4 3
*/

//
//  main.cpp
//  Dima and Staircase
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli a[MAXN];

int main(int argc, const char * argv[]) {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	lli ans = 0;
	lli h1 = 0, w1 = 0, h2, w2;
	for (int i = 0; i < m; ++i) {
		cin >> w2 >> h2;
		ans = max(ans + h1, a[w2]);
		cout << ans << endl;
		h1 = h2;
		w1 = w2;
	}

	return 0;
}
