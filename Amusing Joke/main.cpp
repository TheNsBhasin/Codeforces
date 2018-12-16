/*input
SANTACLAUS
DEDMOROZ
SANTAMOROZDEDCLAUS
*/

//
//  main.cpp
//  Amusing Joke
//
//  Created by Nirmaljot Singh Bhasin on 08/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	string a, b, c;
	cin >> a >> b >> c;
	lli freq[26];
	memset(freq, 0, sizeof(freq));
	for (int i = 0; i < a.length(); ++i) {
		++freq[a[i] - 'A'];
	}
	for (int i = 0; i < b.length(); ++i) {
		++freq[b[i] - 'A'];
	}
	for (int i = 0; i < c.length(); ++i) {
		--freq[c[i] - 'A'];
	}
	bool flag = true;
	for (int i = 0; i < 26; ++i) {
		if (freq[i] != 0) {
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
