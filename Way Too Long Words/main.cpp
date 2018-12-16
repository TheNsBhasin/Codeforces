/*input
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis
*/

//
//  main.cpp
//  Way Too Long Words
//
//  Created by Nirmaljot Singh Bhasin on 08/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		if (str.length() > 10) {
			cout << str[0] << str.length() - 2 << str[str.length() - 1] << endl;
		} else {
			cout << str << endl;
		}
	}
	return 0;
}
