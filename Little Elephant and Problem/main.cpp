/*input
4
4 3 2 1
*/

//
//  main.cpp
//  Little Elephant and Problem
//
//  Created by Nirmaljot Singh Bhasin on 21/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli a[MAXN], b[MAXN];

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	lli cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			++cnt;
		}
	}
	if (cnt > 2) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
	return 0;
}
