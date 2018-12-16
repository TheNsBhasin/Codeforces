/*input
hlelo
*/

//
//  main.cpp
//  Chat room
//
//  Created by Nirmaljot Singh Bhasin on 15/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
	string str;
	cin >> str;
	string word = "hello";
	int j = 0;
	for (int i = 0; i < str.length() && j < word.length(); ++i) {
		if (str[i] == word[j]) {
			++j;
		}
	}
	if (j < word.length()) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
	return 0;
}
