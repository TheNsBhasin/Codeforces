/*input
4 4
case
care
test
code
*/

//
//  main.cpp
//  Removing Columns
//
//  Created by Nirmaljot Singh Bhasin on 23/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 101;

string s[MAXN];
string ans[MAXN];

int main(int argc, const char * argv[]) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int j = 0; j < m; ++j) {
		bool flag = true;
		for (int i = 1; i < n; ++i) {
			if (ans[i - 1] + s[i - 1][j] > ans[i] + s[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int i = 0; i < n; ++i) {
				ans[i] += s[i][j];
			}
		}
	}
	cout << m - ans[0].length() << endl;
	return 0;
}
