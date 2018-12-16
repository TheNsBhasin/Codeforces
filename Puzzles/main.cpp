/*input
4 6
10 12 10 7 5 22
*/

//
//  main.cpp
//  Puzzles
//
//  Created by Nirmaljot Singh Bhasin on 17/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int n, m;
	cin >> n >> m;
	lli f[m];
	for (int i = 0; i < m; ++i) {
		cin >> f[i];
	}
	sort(f, f + m);
	lli ans = LONG_MAX;
	for (int i = 0; i <= m - n; ++i) {
		lli A = f[i + n - 1];
		lli B =	f[i];
		ans = min(ans, A - B);
	}
	cout << ans << endl;
	return 0;
}
