/*input
6 4
*/

//
//  main.cpp
//  Mashmokh and ACM
//
//  Created by Nirmaljot Singh Bhasin on 17/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 2003;
const int MOD = 1e9 + 7;

lli dp[MAXN][MAXN];

int main(int argc, const char * argv[]) {
	lli n, m;
	cin >> n >> m;
	for (int j = 1; j <= n; ++j) {
		dp[1][j] = 1;
	}
	for (int i = 2; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = j; k <= n; k += j) {
				dp[i][k] += dp[i - 1][j];
				dp[i][k] %= MOD;
			}
		}
		for (int x = 1; x <= m; ++x) {
			for (int y = 1; y <= n; ++y) {
				cout << dp[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	lli ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += dp[m][i];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
