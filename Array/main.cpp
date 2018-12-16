/*input
7 4
4 7 7 4 7 4 7
*/
//
//  main.cpp
//  Array
//
//  Created by Nirmaljot Singh Bhasin on 21/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <utility>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli a[MAXN], cnt[MAXN];

pair<lli, lli> solve(lli n, lli k) {
	lli distinct = 0;
	for (int i = 1; i <= n; ++i) {
		if (!cnt[a[i]]) {
			++distinct;
		}
		++cnt[a[i]];
	}
	if (distinct < k) {
		return { -1, -1};
	}
	lli low = 1, high = n;
	while (low <= high && distinct >= k) {
		--cnt[a[high]];
		if (!cnt[a[high]]) {
			--distinct;
		}
		--high;
	}
	if (distinct < k) {
		++high;
		++cnt[a[high]];
		++distinct;
	}
	while (low <= high && distinct >= k) {
		--cnt[a[low]];
		if (!cnt[a[low]]) {
			--distinct;
		}
		++low;
	}
	if (distinct < k) {
		--low;
		++cnt[a[low]];
		++distinct;
	}
	return {low, high};
}

int main(int argc, const char * argv[]) {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	pair<lli, lli> res = solve(n, k);
	cout << res.first << " " << res.second << endl;
	return 0;
}
