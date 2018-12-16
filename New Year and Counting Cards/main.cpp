/*input
0ay1
*/

//
//  main.cpp
//  New Year and Counting Cards
//
//  Created by Nirmaljot Singh Bhasin on 29/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}

bool isOdd(char c) {
	if (c == '1' || c == '3' || c == '5' || c == '7' || c == '9') {
		return true;
	}
	return false;
}

int main(int argc, const char * argv[]) {
	string str;
	cin >> str;
	lli ans = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (isVowel(str[i]) || isOdd(str[i])) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
