/*input
aaba
2
*/

//
//  main.cpp
//  Kolya and Tandem Repeat
//
//  Created by Nirmaljot Singh Bhasin on 23/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

string s;
int m;

int main(int argc, const char * argv[]) {
	cin >> s;
	cin >> m;
	lli len = s.length();
	if (len <= m) {
		cout << (((len + m) >> 1) << 1) << endl;
		return 0;
	}
	lli ans = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 1; j <= len - i; ++j) {
			lli cnt = 0;
			for (int k = i; k < i + j; ++k) {
				if ((k + j >= len && k + j < len + m) || (k + j < len && s[k] == s[k + j])) {
					++cnt;
				}
			}
			if (j == cnt) {
				ans = max(ans, cnt);
			}
		}
	}
	cout << (ans << 1) << endl;
	return 0;
}
