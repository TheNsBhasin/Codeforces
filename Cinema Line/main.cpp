/*input
4
50 50 25 25
*/

//
//  main.cpp
//  Cinema Line
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli q[MAXN];
lli cnt[3];

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> q[i];
	}
	bool flag = true;
	for (int i = 0; flag && i < n; ++i) {
		if (q[i] == 25) {
			++cnt[0];
		} else if (q[i] == 50) {
			++cnt[1];
			if (cnt[0]) {
				--cnt[0];
			} else {
				flag = false;
			}
		} else if (q[i] == 100) {
			++cnt[2];
			if (cnt[1] && cnt[0]) {
				--cnt[0];
				--cnt[1];
			} else if (cnt[0] > 2) {
				cnt[0] -= 3;
			} else {
				flag = false;
			}
		}
	}
	if (flag) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
