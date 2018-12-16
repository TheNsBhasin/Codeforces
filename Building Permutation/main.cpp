/*input
3
-1 -1 2
*/

//
//  main.cpp
//  Building Permutation
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 3 * 100005;

lli a[MAXN];

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	lli res = 0;
	for (int i = 0; i < n; ++i) {
		res += abs(i - a[i] + 1);
	}
	cout << res << endl;
	return 0;
}
