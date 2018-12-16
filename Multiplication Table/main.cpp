/*input
1 10 5
*/

//
//  main.cpp
//  Multiplication Table
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

lli n, m, k;

lli f(lli x) {
	lli res = 0;
	for (int i = 1; i <= n; ++i) {
		res += min(m, x / i);
	}
	return res;
}

int main(int argc, const char * argv[]) {
	cin >> n >> m >> k;
	lli low = 1;
	lli high = m * n;
	while (low <= high) {
		lli mid = low + ((high - low) >> 1);
		if (f(mid) < k) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	cout << low << endl;
	return 0;
}
