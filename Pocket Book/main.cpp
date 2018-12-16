/*input
4 5
ABABA
BCGDG
AAAAA
YABSA
*/

//
//  main.cpp
//  Pocket Book
//
//  Created by Nirmaljot Singh Bhasin on 21/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 102;
const int MOD = 1e9 + 7;

string s[MAXN];
bool vis[26][MAXN];
lli cnt[MAXN];
int n, m;

int main(int argc, const char * argv[]) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (!vis[(s[i][j] - 'A')][j]) {
				vis[(s[i][j] - 'A')][j] = true;
				++cnt[j];
			}
		}
	}
	lli ans = 1;
	for (int i = 0; i < m; ++i) {
		ans = (ans * cnt[i]) % MOD;
	}
	cout << ans << endl;
	return 0;
}
