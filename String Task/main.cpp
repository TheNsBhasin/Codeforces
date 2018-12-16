/*input
xnhcigytnqcmy
*/

//
//  main.cpp
//  String Task
//
//  Created by Nirmaljot Singh Bhasin on 17/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
	string s;
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') {
			continue;
		} else {
			cout << "." << s[i];
		}
	}
	cout << endl;
	return 0;
}
