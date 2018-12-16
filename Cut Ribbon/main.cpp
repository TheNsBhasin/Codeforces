/*input
7 5 5 2
*/

//
//  main.cpp
//  Cut Ribbon
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;

typedef long long int lli;
const int MAXN = 4003;

lli n, a, b, c;
lli dp[MAXN];

lli f(lli len) {
	if (len < 0) {
		return LONG_MIN;
	}
	if (dp[len] != -1) {
		return dp[len];
	}
	dp[len] = max(f(len - a) + 1, max(f(len - b) + 1, f(len - c) + 1));
	return dp[len];
}

int main(int argc, const char * argv[]) {
	fill(dp, dp + MAXN, -1);
	dp[0] = 0;
	cin >> n >> a >> b >> c;
	cout << f(n) << endl;
	return 0;
}
