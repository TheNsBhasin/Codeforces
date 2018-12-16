/*input
3454
*/

//
//  main.cpp
//  Divisibility by Eight
//
//  Created by Nirmaljot Singh Bhasin on 21/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;

typedef long long int lli;
const int MAXN = 102;

lli dp[MAXN][8], pp[MAXN][8];
string s;

void solve(lli i, lli m) {
	if (pp[i][m] == -1) {
		cout << s[i];
		return;
	}
	solve(i - 1, pp[i][m]);
	if ((pp[i][m] * 10 + s[i] - '0') % 8 == m) {
		cout << s[i];
	}
}

int main(int argc, const char * argv[]) {
	cin >> s;
	dp[0][(s[0] - '0') % 8] = 1;
	pp[0][(s[0] - '0') % 8] = -1;
	for (int i = 1; i < s.length(); ++i) {
		lli d = s[i] - '0';
		dp[i][d % 8] = 1;
		pp[i][d % 8] = -1;
		for (int j = 0; j < 8; ++j) {
			if (dp[i][(j * 10 + d) % 8] == 0 && dp[i - 1][j] == 1) {
				dp[i][(j * 10 + d) % 8] = 1;
				pp[i][(j * 10 + d) % 8] = j;
			}
			if (dp[i][j] == 0 && dp[i - 1][j] == 1) {
				dp[i][j] = 1;
				pp[i][j] = j;
			}
		}
	}
	for (int i = 0; i < s.length(); ++i) {
		if (dp[i][0] == 1) {
			cout << "Yes" << endl;
			solve(i, 0);
			cout << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
