/*input
4 10
10
21
27
27
*/

//
//  main.cpp
//  Mr. Kitayuta, the Treasure Hunter
//
//  Created by Nirmaljot Singh Bhasin on 21/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;

typedef long long int lli;
const int MAXN = 30001;

lli p[MAXN];
lli dp[MAXN][250 << 1];
int n, d;

lli solve(lli cur, lli len) {
	if (cur >= MAXN || len <= 0) {
		return 0;
	}
	if (dp[cur][len - (d - 250)] != -1) {
		return dp[cur][len - (d - 250)];
	}

	dp[cur][len - (d - 250)] = p[cur] + max(solve(cur + len - 1, len - 1), max(solve(cur + len, len), solve(cur + len + 1, len + 1)));
	return dp[cur][len - (d - 250)];
}

int main(int argc, const char * argv[]) {
	memset(dp, -1, sizeof(dp));
	memset(p, 0, sizeof(p));
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		lli x;
		cin >> x;
		++p[x];
	}
	lli ans = p[0] + solve(d, d);
	cout << ans << endl;
	return 0;
}
