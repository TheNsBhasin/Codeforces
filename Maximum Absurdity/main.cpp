/*input
6 2
1 1 1 1 1 1
*/

//
//  main.cpp
//  Maximum Absurdity
//
//  Created by Nirmaljot Singh Bhasin on 22/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005 << 1;

lli a[MAXN], sum[MAXN];
pair<lli, lli> ans;
int n, k;

int main(int argc, const char * argv[]) {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	ans = {n - (k << 1) + 1, n - k + 1};
	lli s = (sum[n] - sum[n - k]) + (sum[n - k] - sum[n - (k << 1)]);
	pair<lli, lli> maxi = {n - k + 1, (sum[n] - sum[n - k])};
	for (int i = n - (k << 1); i > 0; --i) {
		lli cur = sum[i + (k << 1) - 1] - sum[i + k - 1];
		if (cur >= maxi.second) {
			maxi = {i + k, cur};
		}
		cur = sum[i + k - 1] - sum[i - 1] + maxi.second;
		if (cur >= s) {
			s = cur;
			ans = {i, maxi.first};
		}
	}
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
