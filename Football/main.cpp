/*input
1000000001
*/

//
//  main.cpp
//  Football
//
//  Created by Nirmaljot Singh Bhasin on 09/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	string str;
	cin >> str;
	lli cnt = 0;
	bool flag = false;
	bool team = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '1') {
			if (team) {
				++cnt;
			} else {
				cnt = 1;
			}
			team = 1;
		} else {
			if (!team) {
				++cnt;
			} else {
				cnt = 1;
			}
			team = 0;
		}
		if (cnt == 7) {
			flag = true;
		}
	}
	if (flag) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
