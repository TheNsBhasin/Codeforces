/*input
110010
*/

//
//  main.cpp
//  Little Elephant and Bits
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
	string s;
	cin >> s;
	bool flag = false;
	for (int i = 0; i < s.length(); ++i) {
		if (!flag && s[i] == '0') {
			flag = true;
			continue;
		}
		if(i == s.length() - 1 && !flag) {
			continue;
		}
		cout << s[i];
	}
	cout << endl;
	return 0;
}
