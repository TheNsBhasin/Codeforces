/*input
7 3
1 2 6 1 1 7 1
*/

//
//  main.cpp
//  Fence
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;

typedef long long int lli;
const int MAXN = 150001;

lli h[MAXN];

int main(int argc, const char * argv[]) {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	lli curr_sum = 0;
	for (int i = 1; i <= k; ++i) {
		curr_sum += h[i];
	}
	lli mini_sum = curr_sum;
	lli res = 1;
	for (int i = k + 1; i <= n; ++i) {
		curr_sum += (h[i] - h[i - k]);
		if (curr_sum < mini_sum) {
			mini_sum = curr_sum;
			res = i - k + 1;
		}
	}
	cout << res << endl;
	return 0;
}
