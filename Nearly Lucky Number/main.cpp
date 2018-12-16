/*input
1000000000000000000
*/

//
//  main.cpp
//  Nearly Lucky Number
//
//  Created by Nirmaljot Singh Bhasin on 08/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	string s;
	cin >> s;
	lli cnt = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '4' || s[i] == '7') {
			++cnt;
		}
	}
	string ans = to_string(cnt);
	bool flag = true;
	for (int i = 0; i < ans.length(); ++i) {
		if ((ans[i] != '4') && (ans[i] != '7')) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
