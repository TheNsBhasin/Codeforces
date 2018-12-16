/*input
aaaa
aaaA
*/

//
//  main.cpp
//  Petya and Strings
//
//  Created by Nirmaljot Singh Bhasin on 08/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
	string a, b;
	cin >> a >> b;
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);
	if (a < b) {
		cout << -1 << endl;
	} else if (a == b) {
		cout << 0 << endl;
	} else {
		cout << 1 << endl;
	}
	return 0;
}
