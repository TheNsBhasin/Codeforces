/*input
3 2
NIE
TAK
NIE
TAK
TAK
TAK
*/

//
//  main.cpp
//  Glad to see you!
//
//  Created by Nirmaljot Singh Bhasin on 31/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

bool query(int a, int b) {
	cout << 1 << " " << a << " " << b << endl;
	fflush(stdin);
	string res;
	cin >> res;
	return (res == "TAK");
}

int bs(int low, int high) {
	if (low > high) {
		return -1;
	}
	while (low < high) {
		int mid = low + ((high - low) >> 1);
		if (query(mid, mid + 1)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

int main(int argc, const char * argv[]) {
	int n, k;
	cin >> n >> k;
	int ans1 = bs(1, n);
	int ans2 = bs(1, ans1 - 1);
	if (ans2 == -1 || !query(ans2, ans1)) {
		ans2 = bs(ans1 + 1, n);
	}
	cout << 2 << " " << ans1 << " " << ans2 << endl;
	fflush(stdin);
	return 0;
}
