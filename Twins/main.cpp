/*input
2
3 3
*/

//
//  main.cpp
//  Twins
//
//  Created by Nirmaljot Singh Bhasin on 15/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 102;

lli arr[MAXN], sum[MAXN];

lli solve(lli n) {
	lli low = 1, high = n;
	while (low <= high) {
		lli mid = low + ((high - low) >> 1);
		if (sum[mid] <= sum[n] - sum[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return low;
}

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	sum[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<lli>());
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + arr[i];
	}
	lli res = solve(n);
	cout << res << endl;
	return 0;
}
