/*input
3 2
BBB
*/

//
//  main.cpp
//  Color Stripe
//
//  Created by Nirmaljot Singh Bhasin on 22/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 5 * 100005;

string s;
int n, k;

int main(int argc, const char * argv[]) {
	cin >> n >> k;
	cin >> s;
	if (k == 2) {
		lli cnt1, cnt2;
		cnt1 = cnt2 = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (i & 1) {
				if (s[i] == 'B') {
					++cnt2;
				} else {
					++cnt1;
				}
			} else {
				if (s[i] == 'A') {
					++cnt2;
				} else {
					++cnt1;
				}
			}
		}
		cout << min(cnt1, cnt2) << endl;
		for (int i = 0; i < s.length(); ++i) {
			if (i & 1) {
				s[i] = ((cnt1 < cnt2) ? 'B' : 'A');
			} else {
				s[i] = ((cnt1 < cnt2) ? 'A' : 'B');
			}
		}
		cout << s << endl;
	} else {
		lli cnt = 0;
		for (int i = 1; i < s.length(); ++i) {
			if (s[i - 1] == s[i]) {
				++cnt;
				for (int j = 0; j < k; ++j) {
					if (s[i] != ('A' + j) && s[i + 1] != ('A' + j)) {
						s[i] = ('A' + j);
						break;
					}
				}
			}
		}
		cout << cnt << endl;
		cout << s << endl;
	}
	return 0;
}
